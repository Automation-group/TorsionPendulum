/***************************************************************************
 *   Copyright (C) 2006 by EB (yfh2@xxxxxxxxxxx)                           *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
 ***************************************************************************/

#include <audio.hh>

#if WORDS_BIGENDIAN
#define SwapLE16(x) ((((u_int16_t)x)<<8)|(((u_int16_t)x)>>8))
#define SwapLE32(x) ((((u_int32_t)x)<<24)|((((u_int32_t)x)<<8)&0x00FF0000) \
                     |((((u_int32_t)x)>>8)&0x0000FF00)|(((u_int32_t)x)>>24))
#else
#define SwapLE16(x) (x)
#define SwapLE32(x) (x)
#endif

#include <QtDebug>

#ifdef Q_OS_LINUX

#include <alsa/asoundlib.h>

#endif

QAlsaSound::QAlsaSound( const QString& filename, QObject* parent): QSound(filename,parent) {

    Path = filename;
    is_available = initialise();

}



bool QAlsaSound::initialise()
{

    if (QSound::isAvailable())
        return TRUE ; 

#ifdef Q_OS_LINUX

    char*   ptr ;
    u_long  databytes ;
    snd_pcm_format_t format;
    snd_pcm_hw_params_t *params;
    int err;

    device = strdup("default");           /* playback device */

    QFile file ( Path );

    if ( ! file.open ( QIODevice::ReadOnly ) ) {
        qCritical() << "Error Opening WAV file:" << Path;
        return FALSE;
    }

    // read all data
    m_data = file.readAll ();

    if ( findchunk (m_data.data(), "RIFF", m_data.size()) == 0 ) {
        fprintf(stdout,"Bad format: Cannot find RIFF file marker\n");   /* wwg: Report error */
        return  FALSE ;
    }

    if ( findchunk (m_data.data(), "WAVE", m_data.size()) == 0 ) {
        qCritical() << "Bad format: Cannot find WAVE file marker";
        return  FALSE ;
    }

    if ( (ptr = findchunk (m_data.data(), "fmt ", m_data.size())) == 0 ) {
        qCritical() << "Bad format: Cannot find 'fmt' file marker";
        return  FALSE ;
    }

    ptr += 4 ;      /* Move past "fmt ".*/
    memcpy (&waveformat, ptr, sizeof (WAVEFORMAT)) ;
    waveformat.dwSize = SwapLE32(waveformat.dwSize);
    waveformat.wFormatTag = SwapLE16(waveformat.wFormatTag) ;
    waveformat.wChannels = SwapLE16(waveformat.wChannels) ;
    waveformat.dwSamplesPerSec = SwapLE32(waveformat.dwSamplesPerSec) ;
    waveformat.dwAvgBytesPerSec = SwapLE32(waveformat.dwAvgBytesPerSec) ;
    waveformat.wBlockAlign = SwapLE16(waveformat.wBlockAlign) ;
    waveformat.wBitsPerSample = SwapLE16(waveformat.wBitsPerSample) ;


    if ( (ptr = findchunk (m_data.data(), "data", m_data.size())) == 0 ) {
        qCritical() << "Bad format: unable to find 'data' file marker";
        return  FALSE ;
    }

    ptr += 4 ;      /* Move past "data".*/
    memcpy (&databytes, ptr, sizeof (u_long)) ;

    samples    = databytes / waveformat.wBlockAlign ;
    datastart  = ((u_long) (ptr + 4)) - ((u_long) (&(m_data.data()[0]))) ;

    switch (waveformat.wBitsPerSample)
        {
        case 8:
            format = SND_PCM_FORMAT_U8 ;
            break;
        case 16:        
            format = SND_PCM_FORMAT_S16_LE ;
            break;
        case 32 :
            format = SND_PCM_FORMAT_S32_LE;
            break;
        default :
            fprintf(stdout,"Bad format: %i bits per seconds\n",waveformat.wBitsPerSample ); /* wwg: report error */
            return  FALSE ;
            break;
        }

    /*
     *      ALSA pain
     */
    snd_pcm_hw_params_alloca(&params);
        

    if ((err = snd_pcm_open (&handle, device,
                             SND_PCM_STREAM_PLAYBACK,SND_PCM_ASYNC)) < 0) {
        fprintf (stdout, "cannot open audio device %s (%s)\n", 
                 device,
                 snd_strerror (err));
        return FALSE;
    }

    if ((err = snd_pcm_nonblock(handle, 1))< 0) {
        fprintf (stdout,"nonblock setting error: %s", snd_strerror(err));
        return FALSE;
    }
        

    /* Init hwparams with full configuration space */
    if (snd_pcm_hw_params_any(handle, params) < 0) {
        fprintf(stdout, "Can not configure this PCM device.\n");
        return FALSE;
    }


    err = snd_pcm_hw_params_set_access(handle, params,
                                       SND_PCM_ACCESS_RW_INTERLEAVED);
    if (err < 0) {
        fprintf(stdout,"Access type not available");
        return FALSE;
    }

    err = snd_pcm_hw_params_set_format(handle, params, format);
    if (err < 0) {
        fprintf(stdout,"Sample format non available");
        return FALSE;
    }

    err = snd_pcm_hw_params_set_channels(handle, params, waveformat.wChannels);
    if (err < 0) {
        fprintf(stdout,"Channels count non available");
        return FALSE;
    }

    err = snd_pcm_hw_params_set_rate_near(handle, params,
                                          &waveformat.dwSamplesPerSec, 0);
    if (err < 0) {
        fprintf(stdout,"Unable to set rate : %d", waveformat.dwSamplesPerSec);
        return FALSE;
    }

    assert(err >= 0);       

    err = snd_pcm_hw_params(handle, params);
    if (err < 0) {
        fprintf(stdout,"Unable to install hw params:");
        return FALSE;
    }

    chunk_size = 0;
    buffer_size=0;
    snd_pcm_hw_params_get_buffer_size(params, &buffer_size);
    snd_pcm_hw_params_get_period_size(params, &chunk_size, 0);
    bits_per_sample = snd_pcm_format_physical_width(format);
    bits_per_frame = bits_per_sample * waveformat.wChannels;
    chunk_bytes = chunk_size * bits_per_frame / 8;
        
    return TRUE ;

#endif

}



void QAlsaSound::play()
{

    if (!is_available)
        return;

#ifdef Q_OS_LINUX
    int f;
    int count = buffer_size;
    for ( int index = 0; index < m_data.size(); index += buffer_size ) {
        // set count
        if ( index + static_cast<int>(buffer_size) >= m_data.size() ) {
            count = m_data.size() - index;
        }

        f=count*8/bits_per_frame;
        while ((frames = snd_pcm_writei(handle, m_data.data() + index, f)) < 0) 
            snd_pcm_prepare(handle);

            /******************************************************************************************
             *   
             *   Portion of code not used, because it does not change the playback 
             *   quality on my box. This code is more or less part of aplay ot other 
             *   players
             *
             *               written=0;
             *               while (f > 0) {
             *
             *                       frames = snd_pcm_writei(handle, buffer2+written, f);
             *                       if (frames == -EAGAIN || (frames >= 0 && frames < f)) 
             *                               snd_pcm_wait(handle, 1000);
             *                       else if (frames < 0)//{
             *                               frames = snd_pcm_recover(handle, frames, 0);
             *                               //snd_pcm_prepare(handle);//}
             *                       if (frames < 0) {
             *                               printf("snd_pcm_writei failed: %s\n", snd_strerror(err));
             *                               break;
             *                       }
             *
             *                       if (frames > 0)
             *                       {
             *                               f -= frames;
             *                               written += frames * bits_per_frame / 8;
             *                       }       
             *               }
             *       
             *****************************************************************************************/


    }
    snd_pcm_drain(handle);

#else

    QSound::play();
#endif
    
}

char* QAlsaSound::findchunk  (char* pstart, char* fourcc, size_t n) {
    char *pend ;
    int   k, test ;

    pend = pstart + n ;

    while (pstart < pend) {
        if (*pstart == *fourcc) {       /* found match for first char*/
            test = TRUE ;
            for (k = 1 ; fourcc [k] != 0 ; k++)
                test = (test ? ( pstart [k] == fourcc [k] ) : FALSE) ;
            if (test)
                return  pstart ;
        } /* if*/
        pstart ++ ;
    }  /* while lpstart*/

    // nothing found
    return 0;
} 
