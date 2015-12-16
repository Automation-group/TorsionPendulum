#ifndef MAINWINDOW_H_
#define MAINWINDOW_H_

#include <QObject>
#include <QDialog>
#include <QPolygonF>
#include "ui_mainWindow.h"
#include "Experiment.h"
#include <QTime>
#include "Pattern.h"
#include "Pendulum.h"

class QwtPlotCurve;

class MainWindow : public QDialog
{
  Q_OBJECT
public:
  MainWindow (QWidget* parent = 0);
  void assign (Experiment* experiment);
  void setPatternInfo (const Pattern& pattern);
  void setPendulumInfo (const Pendulum& pendulum);
public slots:
  /**
   * \param G Модуль сдвига
   * \param Q Затухание
   * \param R Коэф. корреляции
   * \param T Тепература
   */
  void dataReady (double G, double Q, double R, double T, double period);
  
  void temperatureReady (double temperature, double speed);
  void powerReady (double power);
signals:
  void configurePendulum ();
  void showPendulumViewer ();
  void showOscillograph ();
private slots:
  void onStart ();
  void onCoolingView (bool value);
  void on_vsCorell_valueChanged (int value);
private:
  void createPlotCurve ();
  void createToolBars ();
  void createMenus ();
  void createActions ();
  void updateDataPlots ();
private:
  Ui_MainWindow ui;
  QwtPlotCurve* pcDataCoolingG;
  QwtPlotCurve* pcDataCoolingQ;
  QPolygonF dataCoolingG;
  QPolygonF dataCoolingQ;
  
  QVector<double> dataCoolingR;
  QVector<double> dataHeatingR;
  
  QwtPlotCurve* pcDataHeatingG;
  QwtPlotCurve* pcDataHeatingQ;
  QPolygonF dataHeatingG;
  QPolygonF dataHeatingQ;
  
  QwtPlotCurve* pcDataT;
  QPolygonF dataT;
  
  QTime tempTimer;
  bool isHeating;
};

#endif /*MAINWINDOW_H_*/
