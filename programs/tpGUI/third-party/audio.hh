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
 *                                                                         *
 * See http://lists.trolltech.com/qt-interest/2007-01/thread00147-0.html   *
 *
 ***************************************************************************/

#ifndef AUDIO_HH
#define AUDIO_HH

#include <QSound>

#ifdef Q_OS_LINUX
#include <QFile>
#include <QByteArray>
#include <alsa/asoundlib.h>
#endif

typedef  struct {
    u_int32_t  dwSize ;
    u_int16_t  wFormatTag ;
    u_int16_t  wChannels ;
    u_int32_t  dwSamplesPerSec ;
    u_int32_t  dwAvgBytesPerSec ;
    u_int16_t  wBlockAlign ;
    u_int16_t  wBitsPerSample ;
} WAVEFORMAT ;


class QAlsaSound : public QSound {
    Q_OBJECT
public :
    QAlsaSound( const QString& filename, QObject* parent=0) ;

    QString Path ;
    bool initialise() ; 
    bool isAvailable() { return is_available ; }
    bool is_available;
    void play();    

private:
    /* ALSA parameters */
    snd_pcm_t               *handle;
    snd_pcm_sframes_t       frames;
    char                    *device ;                        /* playback device */
    snd_pcm_uframes_t chunk_size, buffer_size;
    size_t bits_per_sample, bits_per_frame, chunk_bytes;

    // the raw data array
    QByteArray m_data;
    
    char* findchunk(char* pstart, char* fourcc, size_t n);
    WAVEFORMAT waveformat ;
    u_long samples, datastart;

};

#endif // AUDIO_HH
