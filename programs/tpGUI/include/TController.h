#ifndef TCONTROLLER_H_
#define TCONTROLLER_H_

#include <QObject>
#include <QTimer>
#include <QlfRNet.h>
#include <QTime>
#include <QPolygonF>

class TController : public QObject
{
  Q_OBJECT
public:
  /**
   * Конструктор
   * 
   */
  TController (QlfRNet* metakon, int devAddress = 0, int channel = 0);
   
public slots:  
  /** Устоновить скорость нагрева
   * \param скорость нагрева °C/мин. 
   */
  void setHeatingSpeed (int hSpeed);
    
  /**
   * Запустить измерения температуры
   */
  void startMeasurements ();
  
  /**
   * Остановить измерения температуры
   */
  void stopMeasurements ();
  
  /** Начать нагрев 
   */  
  void startHeating ();
  
  /** Остановить нагрев
   */
  void stopHeating ();
  
  /** Задать уставку
   */
  void setPoint (int temperature);
  
  /**
   * Задать ПИД пар-ры
   */
  void setPID (int integr, int diff, int pb = 1);
  
  void setMaxPower (int power);
signals:
  void temperatureRead (double temperature, double speed);
  void powerRead (double power);
  void disconnected ();
protected slots:
  void onTimer ();
  void onPowerTimer ();
  void onHeatingTimer ();
private:
  double readTemperature ();
  double calcSpeed (const QPolygonF& data) const;
private:
  QlfRNet* metakon;
  QTimer powerTimer;
  QTimer timer;
  QTimer heatingTimer;
  int heatingSpeed;
  double startHTemperature;
  double currentHTemperature;
  QPolygonF tempBuffer;
  QTime startHeatingTime; 
  int devAddress;
  int channel;
  bool disconnectedFirst;
};

#endif /*TCONTROLLER_H_*/
