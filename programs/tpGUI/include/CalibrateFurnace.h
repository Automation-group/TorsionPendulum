#ifndef CALIBRATEFURNACE_H_
#define CALIBRATEFURNACE_H_

#include <QDialog>
#include <QPolygonF>
#include <QTime>
#include "ui_calibrateFurnace.h"
#include <qwt_plot_curve.h>

class CalibrateFurnace: public QDialog
{
  Q_OBJECT
public:
  CalibrateFurnace ();
public slots:
  void temperatureRead (double temperature, double speed);
signals:
  /**
   * Задать уставку
   */
  void setPoint (int newSetPoint);
  
  /**
   * Начать измерения температуры
   */
  void start ();
  
  /**
   * Остановить измерения температуры
   */
  void stop ();
private slots:
  void onStart ();
private:
  Ui_CalibrateFurnaceDialog ui;
  QTime startTime;
  QPolygonF data;
  QwtPlotCurve *dataCurve;
  double maxTemperature;
  int _setPoint;
  bool setPointFlag;
};

#endif /*CALIBRATEFURNACE_H_*/
