#include "PController.h"
#include <QVector>
#include <math.h>
#include <QtDebug>
#include <QlfTornPend.h>
#include "tpGlobal.h"

PController::PController (QlfTornPend* tPend)
  : tornPend (tPend), deviationTimer (), 
  fluctCount (60), skipFluctCount (5),
  periodCalibrationCoeff (442921.54 * 10.0 / 3.0),
  running (false), pausing (false), fluctMinAmpl (1.0),
  pendulumZero (0.0), deviationFailedCounter (0)
{
  deviationFailedTimer.setInterval (1300);
  deviationFailedTimer.setSingleShot (true);
  connect (&deviationFailedTimer, SIGNAL(timeout()),
      this, SLOT (deviationFailedTimeout ()));
  
  deviationTimer.setInterval (4000);
  deviationTimer.setSingleShot (true);
  connect (&deviationTimer, SIGNAL(timeout()),
      this, SLOT (deviationTimeout ()));
  
  pedulumStateTimer.setInterval (1300);
  pedulumStateTimer.setSingleShot (true);  
  connect (&pedulumStateTimer, SIGNAL(timeout()),
      this, SLOT (pedulumStateTimeout ()));
  
  connect (tornPend, SIGNAL(periodDataReaded(int,int,int,int)),
      this, SLOT (periodDataReaded(int,int,int,int)));
}

PController::~PController ()
{
  
}

void PController::setFluctCount (int newFluctCount)
{
  fluctCount = newFluctCount;
}

void PController::setDeviationTime (int msTimeout)
{
  deviationTimer.setInterval (msTimeout);
}

void PController::setFluctMinAmpl (double minAmpl)
{
  fluctMinAmpl = minAmpl;
  qDebug ("setFluctMinAmpl %lf", fluctMinAmpl);
}

void PController::setSkipFluctCount (int newValue)
{
  skipFluctCount = newValue;
}

void PController::zeroControl (bool enable)
{
  zeroControlEnabled = enable;
}

bool PController::zeroControlState ()
{
  return zeroControlEnabled;
}

void PController::runMeasurements ()
{
  if (running) return;
  running = true;
  if (! pausing) runMeasurement ();
}

void PController::stopMeasurements ()
{
  if (!running) return;
  running = false;
  pause (false);
  tornPend -> stop (); 
}

void PController::pause (bool enable)
{
  if (pausing == enable) return;
  
  pausing = enable;
  paused (pausing);
  
  if (!running) return;
  
  if (pausing)
  {
    deviationTimer.stop ();
    tornPend -> stop ();
    tornPend -> disableMagnet ();    
  }
  else
    runMeasurement ();
}

double PController::calcDecrement (const QPolygonF& data) const
{
  double xsum = 0, ysum = 0;
  double xysum = 0, xxsum = 0;
  int count = 0; 
  
  for(QPolygonF::const_iterator i = data.constBegin (); i != data.constEnd (); ++i)
  {
    double y = (*i).y ();
    double x = (*i).x ();    
    ysum += y;
    xsum += x;
    xysum += x * y;
    xxsum += x * x;
    count ++;
  }  
  return (xsum * ysum - xysum * count) / (count * xxsum - xsum * xsum) / PI;
}

double PController::calcCorrelationCoeff (const QPolygonF& data) const
{
  double ysum = 0.0;
  double xsum = 0.0;
  int count = 0;
  for(QPolygonF::const_iterator i = data.constBegin (); i != data.constEnd (); ++i)
  {
    ysum += (*i).y ();
    xsum += (*i).x ();
    count ++;
  }
  
  ysum /= (double)count;
  xsum /= (double)count;
  
  double sum1 = 0.0, sumx2 = 0.0, sumy2 = 0.0;
  for(QPolygonF::const_iterator i = data.constBegin (); i != data.constEnd (); ++i)
  {
    double y = (*i).y () - ysum;
    double x = (*i).x () - xsum;
    sum1 += x * y;
    sumx2 += x * x;
    sumy2 += y * y;
  }
  
  return - sum1 / sqrt (sumx2 * sumy2);
}

void PController::adcCodeReaded (int code)
{
  
}

void PController::pedulumStateTimeout ()
{
  qDebug ("Calling pedulumStateTimeout");
  
  if (!pausing)
  {
    pausing = true;
    paused (pausing); 
  }  
  
  if (tornPend -> state () == QlfTornPend::Disconnected)
  {
    disconnected ();
    qDebug ("Pendulum disconnected");
  }
}

void PController::periodDataReaded (int number, int maxAmpl, int minAmpl, int period)
{
  pedulumStateTimer.stop ();
  deviationFailedCounter = 0;
  deviationFailedTimer.stop ();
  
  static bool firstBigAmplitude = true;
  
  if (!running) return;
  if (pausing) return;
  
  if (number) deviationFailedTimer. stop ();
   
  if ( number <= skipFluctCount )
  {
    firstBigAmplitude = true;
    return;
  }
  
  if ( number == (skipFluctCount + 1) && ((maxAmpl - minAmpl) < 400)) smallAmplitude ();
  
  if ( firstBigAmplitude && ((maxAmpl > 500) || (minAmpl < -500)) )
  {
    firstBigAmplitude = false;
    bigAmplitude ();
  }
  
  const double coeff = 1e-2;
  double amplitude = (maxAmpl - minAmpl) * coeff;
  
  if ( (number >= fluctCount) || (amplitude < fluctMinAmpl) )
  {
    endMeasurement ();
    runMeasurement ();
    return;
  }
       
  measurementReaded (number, maxAmpl * coeff, minAmpl * coeff, period / periodCalibrationCoeff);
  pendulumZero += maxAmpl + minAmpl;
  data << QPointF (number, log ( amplitude ) );
  averagePeriod += period;
  
  pedulumStateTimer.start ();
}

void PController::deviationTimeout ()
{
  tornPend -> disableMagnet ();
  tornPend -> run ();
  deviationFailedTimer.start ();
  beginMeasurement ();
}

void PController::runMeasurement ()
{
  pendulumZero = 0.0;
  averagePeriod = 0.0;
  data.clear ();
  tornPend -> enableMagnet ();
  deviationTimer.start ();
}

void PController::deviationFailedTimeout ()
{
  if (tornPend -> state () == QlfTornPend::Disconnected)
  {
    disconnected ();
    qDebug ("Pendulum disconnected");
    return;
  }
  
  deviationFailedCounter ++;
  if (deviationFailedCounter < 3)
    runMeasurement ();
  else
  {
    deviationFailed ();
    qDebug ("Deviation failed");
    pause (true);
  }
}

void PController::endMeasurement ()
{ 
  if ( !data.empty ())
  {
    averagePeriod /= periodCalibrationCoeff * (double)data.count ();
    double decrement = calcDecrement (data);
    double coeffCorrel = calcCorrelationCoeff (data);
    endMeasurement (averagePeriod, decrement, coeffCorrel);
    qDebug ("End Mst period %3.3lf; decrement %e; coeffCorrel %3.3lf", averagePeriod, decrement, coeffCorrel);    
  }
  
  int zAddition = 0;
  
  if (!data.empty ())
  {
    pendulumZero /= (double)data.count ();
    if ( pendulumZero > 45) zAddition = -1;
    if ( pendulumZero < -45) zAddition = 1;
  }

  if (zAddition)
  {
    if (zeroControlEnabled)
    {
      int resCode = tornPend -> getResistorCode ();
      if (resCode == 0 || resCode == 255) zeroControlFailed ();
        else tornPend -> setResistorCode ( resCode + zAddition);
    }
    else
      zeroWarning ();
  }
}
