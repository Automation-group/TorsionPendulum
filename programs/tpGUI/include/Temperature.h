#ifndef TEMPERATURE_H_
#define TEMPERATURE_H_

#include <QObject>
#include <QTimer>
#include <QlfRNet.h>

class Temperature: public QObject
{
  Q_OBJECT
public:
  Temperature (QlfRNet* rnet);
signals:
  /**
   * Измерена температура
   * \param temperature температура
   */
  void temperatureMeasurement (double temperature);
  
  
  /**
   * Информация о скорости нагрева
   * \param tempSpeed Скорость нагрева 
   */
  void tempSpeedDigest (double tempSpeed);
  
protected slots:
  void onTimer ();
private:
  QlfRNet* metakon;
  QTimer* timer;
};

#endif /*TEMPERATURE_H_*/
