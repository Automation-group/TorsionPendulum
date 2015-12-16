#ifndef TEXTINFORMANT_H_
#define TEXTINFORMANT_H_

#include <QDialog>
#include <QTextEdit>

class TextInformant: public QDialog
{
  Q_OBJECT
public:
  TextInformant ();
  
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
  
  void dataReady (double G, double Q, double R, double T, double period);
  
  void setMaxTemperature (int temp);
  
private:
  void addMessage (const QString& text);
  int maxTemp;
  QTextEdit* messages;
};

#endif /*TEXTINFORMANT_H_*/
