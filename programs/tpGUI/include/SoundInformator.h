#ifndef SOUNDINFORMATOR_H_
#define SOUNDINFORMATOR_H_

#include <QThread>
#include <QString>
#include <QStringList>
#include <QMutex>
#include <QWaitCondition>

class SoundInformator: public QThread
{
  Q_OBJECT
public:
  SoundInformator ();
  ~SoundInformator ();
public slots:
  /**
   * Измерение началось
   */
  void beginMeasurement ();
  
  /**
   * Маятник был отсоединен или выключен
   */
  void pendulumDisconnected ();
  
  void metakonDisconnected ();
  
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
  
  void temperatureRead (double temperature, double speed);
  
  void dataReady (double G, double Q, double R, double T);
  
  void setMaxTemperature (int temp);
protected:
  void run ();
private:
  void addToPlay (const QString& filename);
  void addToRepeat (const QString& filename);
  void play (const QString& filename);
private:
  bool terminated;
  QStringList playList;
  QStringList repeatList;
  QMutex playListMutex;
  QWaitCondition playListWaitCondition;
  int maxTemp;
};

#endif /*SOUNDINFORMATOR_H_*/
