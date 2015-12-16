#ifndef TPSIMULATOR_H_
#define TPSIMULATOR_H_

#include <QObject>
#include <QThread>
#include <QIODevice>

class TPSimulator: public QThread
{
  Q_OBJECT
public:
  /** Конструктор
   * \param in входной поток данных
   * \param out выходной поток данных
   */
  TPSimulator (QObject* parent = 0);
  
  ~TPSimulator ();
  
  /** Задать затухание
   * \param newDec затухание 
   */
  void setDecrement (double newDec);
  
  /** Задать частоту колебаний маятника 
   * \param newFreq частота колебаний, Гц
   */
  void setFrequency (double newFreq);
  
  void setFirstAmplitude (int newFAmpl);
  
public slots: 
  /** Запустить маятник в режиме АЦП */
  void runADC ();
  
  /** Остановить маятник в режиме АЦП */
  void stopADC ();
  
  /** Запустить маятник в режиме настройки*/
  void runPreviewMode ();
  
  /** Запустить маятник */
  void runMeasurements ();
  
  /** Остановить маятник */
  void stop ();
  
  /** Нажата кнопка отклонения магнита на передней панели */
  void hardEnableMagnet ();
  
  /** Включить магнит */
  void enableMagnet ();
  
  /** Выключить магнит */
  void disableMagnet ();
  
public:  
  /** Получить состояние маятника */
  char getState ();
  int getResistor ();
  void setResistor (int resCode);
  
  double getZeroResistor ();
  void setZeroResistor (double resCode);
  
signals:
  void periodIsReady (int number, int maxAmpl, int minAmpl, int period);
  void adcIsReady (int code);
protected:
  void run ();
  void onADC (int code);
  void onPeriod (int maxAmpl, int minAmpl, int period);
private:
  double decrement;
  double frequency;
  int resistorCode;
  bool adcIsRunning;
  bool measurementsIsRunning;
  bool enablePreview;
  bool magnetEnabled;
  bool terminated;
  double firstAmplitude;
  int periodNumber;
  // для оценки периода как в МК
};

#endif /*TPSIMULATOR_H_*/
