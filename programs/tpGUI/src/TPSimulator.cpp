#include "TPSimulator.h"
#include <math.h>
#include <QTime>
#include <QtDebug>
#include <time.h>

TPSimulator::TPSimulator (QObject* parent)
  : QThread (parent), 
  decrement (12.0e-3), frequency (6.0), resistorCode (127),
  adcIsRunning (false), measurementsIsRunning (false),
  enablePreview (false), terminated (false),
  firstAmplitude (340), 
  magnetEnabled (false), periodNumber (0)
{
  QThread::start ();
}
  
TPSimulator::~TPSimulator ()
{
  terminated = true;
  wait ();
}

void TPSimulator::setDecrement (double newDec)
{
  decrement = newDec;
}
  
void TPSimulator::setFrequency (double newFreq)
{
  frequency = newFreq;
}
  
void TPSimulator::runADC ()
{
  adcIsRunning = true;
}
  
void TPSimulator::stopADC ()
{
  adcIsRunning = false;
}
  
void TPSimulator::runPreviewMode ()
{
  periodNumber = 0;
  measurementsIsRunning = true;
}
  
void TPSimulator::runMeasurements ()
{
  periodNumber = 0;
  measurementsIsRunning = true;
}
  
void TPSimulator::stop ()
{
  measurementsIsRunning = false;
}
  
void TPSimulator::hardEnableMagnet ()
{
  enableMagnet ();
  runPreviewMode ();
}

/** Включить магнит */
void TPSimulator::enableMagnet ()
{
  magnetEnabled = true;
  sleep (1);
}

/** Выключить магнит */
void TPSimulator::disableMagnet ()
{
  magnetEnabled = false;
}

void TPSimulator::setFirstAmplitude (int newFAmpl)
{
  firstAmplitude = newFAmpl;
}
  
void TPSimulator::onPeriod (int maxAmpl, int minAmpl, int period)
{
  if (measurementsIsRunning)
  {
    periodIsReady (periodNumber, maxAmpl, minAmpl, period);
    //  qDebug () << "PR " << maxAmpl << "," << minAmpl << "," << period * 0.0006773;// / (442921.54 * 10.0 / 3.0) * 1000.0;
    periodNumber ++;
  }
}

void TPSimulator::onADC (int code)
{  
  
  static int adcCounter = 0;
  if (adcCounter == 3)
  {
    if (adcIsRunning) adcIsReady (code);
    adcCounter = 0;
  }
  else
    adcCounter++;
  
  static int periodAMin = 0;
  static int periodAMax = 0;
  
  static int adcMin = 32000;
  static int adcMax = -32000;
  static int adcPred = 0;
  static int adcResult = 0;

  static const int ADC_Buf_Size = 4;
  static int adc_Buf[ADC_Buf_Size];
  static unsigned char adc_Buf_Index = 0;  
  
  static long predPeriodAddition = 0;
  static long estPeriod = 0;
  static unsigned long timer = 0;
  
  /* Из МК */
  adcResult = code;
  timer ++;
  
  if (adcMin > adcResult)
    adcMin = adcResult;

  if (adcMax < adcResult)
    adcMax = adcResult;
  
  adc_Buf[adc_Buf_Index] = adcResult;
  
  if ((adcPred <= 0) && (adcResult > 0) && (adcMin < -19) && (adcMax > 19))
  {  
    estPeriod = timer;
    timer = 0;
    periodAMax = adcMax;
    periodAMin = adcMin; 
    adcMax = -32000;
    adcMin = 32000;  
  }   
  
  static int flag = 0;
  
  if ((timer == 1) && (periodAMax > 19))
  { 
    
    long Sxi = 0, Sxixi = 0, Sxiyi = 0, Syi = 0;
    int j = adc_Buf_Index;
    
    for(int i=0;i<ADC_Buf_Size;i++)
    { 
      j++;
      if (j == ADC_Buf_Size) j = 0;
      
      Sxi += (long)i;
      Sxixi += (long)i * (long)i;
      Syi += (long)adc_Buf[j];
      Sxiyi += (long)adc_Buf[j] * (long)i;      
    }
    
    long pAddition = (Syi * Sxixi - Sxi * Sxiyi) * 1000;
    pAddition /= (Sxi * Syi - (long)ADC_Buf_Size * Sxiyi);
    
    long period = estPeriod  * 1000 + pAddition - predPeriodAddition;
    onPeriod (periodAMax, periodAMin, period);
    predPeriodAddition = pAddition;    
  }
  
  adcPred = adcResult;
  
  adc_Buf_Index++;
  if (adc_Buf_Index == ADC_Buf_Size) adc_Buf_Index = 0;  
  
}

void TPSimulator::run ()
{
  double t = 0.0;
  do
  {
    if (magnetEnabled) t = 0.0;    
    double input = firstAmplitude * exp(-decrement * t) * cos (2.0 * 3.1415926535897931 * frequency * t) ;
    int code = (int) input;
    if (code > 510) code = 511;
    if (code < -511) code = -512;
    onADC (code);
    t += 0.0006773;
    struct timespec ts1, ts2;
    clock_gettime ( CLOCK_REALTIME, &ts1 );
    do
    {
      clock_gettime ( CLOCK_REALTIME, &ts2 );
      ts2.tv_nsec += (ts2.tv_sec - ts1.tv_sec) * 1000000000;
    }while ( (ts2.tv_nsec - ts1.tv_nsec) < 677200);
    
  }while (!terminated);
}
