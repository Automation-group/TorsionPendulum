#ifndef EXPCONFIGDIALOG_H_
#define EXPCONFIGDIALOG_H_

#include <QDialog>
#include "ui_tpExpSettingsDialog.h"

class ExpConfigDialog: public QDialog
{
  Q_OBJECT
public:
  ExpConfigDialog ();
  
public slots:
  void applaySettings ();
signals:
  /**
   * Сигнал установить кол-во колебаний по которым ведется расчет данных. 
   * \param newFluctCount Кол-во колебаний.
   */
  void setFluctCount (int newFluctCount);
  
  /**
   * Сигнал установить время отклонения маятника
   * \param msTime Время отклонения, мс.
   */
  void setDeviationTime (int msTime);
  
  /**
   * Сигнал установить минимальную амплитуду колебаний.
   * Если амлитуда колебаний станет меньше заданной измерение будет закончено.
   * \param minAmpl Мин. амплитуда.
   */
  void setFluctMinAmpl (double minAmpl);
  
  /**
   * Сигнал установить сколько начальных колебаний пропустить (игнорировать).
   * \param newValue Кол-во колебаний.
   */
  void setSkipFluctCount (int newValue);
  
  /**
   * Сигнал включить/выключить автомат. подстройку нуля.
   * \param state true - включить; false - выключить.
   */
  void zeroControl (bool enable);
 
  /** Сигнал устоновить скорость нагрева
   * \param скорость нагрева °C/мин. 
   */
  void setHeatingSpeed (int hSpeed);
  
  /**
   * Установить температуру охлаждения
   */
  void setMaxTemperature (int temp);
  
private slots:
  void onOk ();
private:
  void saveDialog ();
  void loadDialog ();
private:
  Ui_ExpSettingsDialog ui;
};

#endif /*EXPCONFIGDIALOG_H_*/
