#ifndef PCONTROLLER_H_
#define PCONTROLLER_H_

#include <QObject>
#include <QThread>
#include <QPolygonF>
#include <QlfTornPend.h>
#include <QTimer>

class PController: public QObject
{
  Q_OBJECT
public:
  /**
   * Конструктор
   * 
   */
  PController (QlfTornPend* tPend);
  
  /**
   * Деструктор
   */
  ~PController ();
  
  bool isPaused () const { return pausing; };
  
  /**
   * Вернуть состояние авто подстройки нуля
   * @return true - включена
   */
  bool zeroControlState ();
  
  /**
   * Установить калибровочный коэф. для периода
   * \param newValue коэф. ед./сек 
   */
  void setPeriodCalibrationCoeff (double newValue); 
  
public slots:  
  /**
   * Установить кол-во колебаний по которым ведется расчет данных. 
   * \param newFluctCount Кол-во колебаний.
   */
  void setFluctCount (int newFluctCount);
  
  /**
   * Установить время отклонения маятника
   * \param msTime Время отклонения, мс.
   */
  void setDeviationTime (int msTime);
  
  /**
   * Установить минимальную амплитуду колебаний.
   * Если амлитуда колебаний станет меньше заданной измерение будет закончено.
   * \param minAmpl Мин. амплитуда.
   */
  void setFluctMinAmpl (double minAmpl);
  
  /**
   * Установить сколько начальных колебаний пропустить (игнорировать).
   * \param newValue Кол-во колебаний.
   */
  void setSkipFluctCount (int newValue);
  
  /**
   * Включить/выключить автомат. подстройку нуля.
   * \param state true - включить; false - выключить.
   */
  void zeroControl (bool enable);
  
  // коэфф. пересчета для периода
  //void setPeriodKoeff
      
  /**
   * Запустить измерения
   */
  void runMeasurements ();
  
  /**
   * Остановить измерения
   */
  void stopMeasurements ();
  
  /**
   * Временно остановить измерения
   */
  void pause (bool enable);
  
signals:
  /**
   * Измерение началось
   */
  void beginMeasurement ();
  
  /**
   * Измерение закончено
   * \param period Период колебаний, с
   * \param decrement Декремент затухания
   * \param correlation Коэф. корреляции
   */
  void endMeasurement (double period, double decrement, double correlation);
  
  /**
   * Прочитано измерение
   * \param number Номер колебания
   * \param maxAmpl Максимальная амплитуда
   * \param minAmpl Минимальная амплитуда
   * \param period Период, сек
   */
  void measurementReaded (int number, double maxAmpl, double minAmpl, double period);
  
  void adcReaded (int code);
  
  //void measurementReaded (int number, int maxAmpl, int minAmpl, int period);
  
  /**
   * Маятник был отсоединен или выключен
   */
  void disconnected ();
  
  /**
   * Маятник подключен
   */
  void connected (); 
  
  /**
   * Маятник был переведен или выведен из режима пауза
   */
  void paused (bool enable);
  
  /**
   * Не могу отрегулировать ноль
   */
  void zeroControlFailed ();
  
  /** Ноль вышел из диапазона
   */
  void zeroWarning ();
  
  /**
   * Слишком большая амплитуда колебаний
   */
  void bigAmplitude ();
  
  /**
   * Слишком маленькая амплитуда колебаний
   */
  void smallAmplitude ();
  
  /**
   * Не могу отклонить образец
   */
  void deviationFailed ();  

protected slots:
  void adcCodeReaded (int code);
  void periodDataReaded (int number, int maxAmpl, int minAmpl, int period);
  void deviationTimeout ();
  void deviationFailedTimeout ();
  void pedulumStateTimeout ();
private:
  double calcDecrement (const QPolygonF& data) const;
  double calcCorrelationCoeff (const QPolygonF& data) const;
  void runMeasurement ();
  void endMeasurement ();
private:
  QTimer deviationTimer;
  QTimer deviationFailedTimer;
  QTimer pedulumStateTimer;
  QlfTornPend* tornPend;
  QPolygonF data;
  double averagePeriod;
  bool isPause;
  bool terminated;
  int fluctCount;
  int skipFluctCount;
  double periodCalibrationCoeff;
  bool running;
  bool pausing;
  double fluctMinAmpl;
  bool zeroControlEnabled;
  double pendulumZero;
  int deviationFailedCounter;
};

#endif /*PCONTROLLER_H_*/
