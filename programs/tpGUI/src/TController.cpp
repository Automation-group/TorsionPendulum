#include "TController.h"
#include <QtDebug>
#include "tpGlobal.h"

TController::TController (QlfRNet* metakon, int devAddress, int channel)
  : metakon (metakon), heatingSpeed (0),
  startHTemperature (0.0), currentHTemperature (0.0),
  devAddress (devAddress), channel (channel), disconnectedFirst (true)
{
  connect (&timer, SIGNAL(timeout()), this, SLOT(onTimer()));
  connect (&heatingTimer, SIGNAL(timeout()), this, SLOT(onHeatingTimer()));
  connect (&powerTimer, SIGNAL(timeout()), this, SLOT(onPowerTimer()));
}

void TController::setHeatingSpeed (int hSpeed)
{
  heatingSpeed = hSpeed;
  tpSettings ().beginGroup ("HeatingSpeed-TimeDelay");
  int interval = tpSettings ().value(QString::number (hSpeed), 60000).toInt();
  tpSettings ().endGroup ();
  heatingTimer.setInterval (interval);
  qDebug () << tr("Установлена скорость нагрева, °C/мин") << hSpeed;
  qDebug () << tr("Задан интервал таймера 'нагрева', мс") << interval;
}

void TController::startHeating ()
{
  tempBuffer.clear ();
  startHeatingTime.start ();
  
  startHTemperature = readTemperature ();
  currentHTemperature = startHTemperature;
  
  temperatureRead (startHTemperature, 0.0);
  
  if (heatingSpeed)
  {
    qDebug () << tr("Включен нагрев");
    onHeatingTimer ();
    heatingTimer.start ();
  }
}

void TController::stopHeating ()
{
  if (heatingTimer.isActive ())
  {
    heatingTimer.stop ();
    setPoint (0);
    qDebug () << tr("Выключен нагрев");
  }
}

void TController::startMeasurements ()
{
  timer.start (300);
  powerTimer.start (5000);
  qDebug () << tr("Измерения температуры запущены");
}

void TController::stopMeasurements ()
{
  timer.stop ();
  powerTimer.stop ();
  qDebug () << tr("Измерения температуры остановлены");
}

double TController::calcSpeed (const QPolygonF& data) const
{
  if (data.isEmpty ()) return 0.0;
  
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
  return (xsum * ysum - xysum * count) / (xsum * xsum - count * xxsum);  
}

void TController::onTimer ()
{
  double temp = readTemperature ();
  tempBuffer << QPointF (startHeatingTime.elapsed () / 1000.0 / 60.0, temp);
  if ( tempBuffer.size () > 120 ) tempBuffer.pop_front ();
  
  double speed = 0.0;
  if ( tempBuffer.size () > 60 )
    speed = calcSpeed (tempBuffer);
  temperatureRead (temp, speed);
}

void TController::onHeatingTimer ()
{
  currentHTemperature += heatingSpeed;
  setPoint ( (int)currentHTemperature);
  qDebug () << tr("Задана уставка ПИД, °C") << currentHTemperature;
}

double TController::readTemperature ()
{
  QlfRNet::RegValue result = metakon -> readReg (devAddress, channel, 1);
  
  if (result.getType () == QlfRNet::RegValue::Nothing)
  {
    if (disconnectedFirst)
    {
      disconnected ();
      disconnectedFirst = false;
    }
    return 0;
  }
  disconnectedFirst = true;
  return result;
}

void TController::onPowerTimer ()
{
  QlfRNet::RegValue result = metakon -> readReg (devAddress, channel, 6);
  
  if (result.getType () == QlfRNet::RegValue::Nothing)
  {
    if (disconnectedFirst)
    {
      disconnected ();
      disconnectedFirst = false;
    }
  }
  else
  {
    disconnectedFirst = true;
    powerRead ((double)result / 100.0);
  }
}

void TController::setPoint (int temperature)
{
  metakon -> writeReg (devAddress, channel, 2, (short int) temperature);
}

void TController::setMaxPower (int power)
{
  metakon -> writeReg (devAddress, channel, 0x0a, (unsigned short) 1);
}

void TController::setPID (int integr, int diff, int pb)
{
  metakon -> writeReg (devAddress, channel, 3, (unsigned short int) pb);
  metakon -> writeReg (devAddress, channel, 4, (unsigned short int) integr);
  metakon -> writeReg (devAddress, channel, 5, (unsigned char) diff);
  qDebug ("setPID integr %i; diff %i; pb %i;", integr, diff, pb);
}
