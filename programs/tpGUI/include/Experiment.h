#ifndef EXPERIMENT_H_
#define EXPERIMENT_H_

#include <QObject>
#include "PController.h"
#include "TController.h"
#include "Pattern.h"
#include "Pendulum.h"


class Experiment : public QObject
{
  Q_OBJECT
public:
  Experiment (PController* pController, TController* tController);
  
  void setPendulum (const Pendulum& pendulum);
  void setPattern (const Pattern& pattern);
public slots:
  void start ();
  void stop ();
  void pause (bool enable);
signals:
  /**
   * \param G Модулб сдвига
   * \param Q Затухание
   * \param R Коэф. корреляции
   * \param T Тепература
   */
  void dataReady (double G, double Q, double R, double T, double period);
  void paused (bool enable);
protected slots:
  void temperatureRead (double temperature, double speed);
  void beginMeasurement ();
  void endMeasurement (double period, double decrement, double correlation);
private:
  Pendulum pendulum;
  Pattern pattern;
  PController* pController;
  TController* tController;
  double currentTemperature;
  double beginMstTemperature;
};


#endif /*EXPERIMENT_H_*/
