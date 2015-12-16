#ifndef PENDULUMVIEWER_H_
#define PENDULUMVIEWER_H_

#include <QWidget>
#include <QPolygonF>
#include "PController.h"

#include <qwt_plot.h>
#include <qwt_plot_curve.h>
#include "ui_pendulumViewer.h"

class PendulumViewer: public QWidget
{
  Q_OBJECT  
public:
  PendulumViewer(QWidget *parent = 0);
  void assign (PController* pController);
public slots:
  void beginMeasurement ();  
  void endMeasurement (double period, double decrement, double correlation);
  void measurementReaded (int number, double maxAmpl, double minAmpl, double period);
private:
  void createTableWidgetItems ();
private:
  Ui_PendViewerForm ui;
  QwtPlot* dataPlot;
  QwtPlotCurve *dataCurve;
  QPolygonF data;
  /*
  QTableWidgetItem* twiNumber;
  QTableWidgetItem* twiPeriod;
  QTableWidgetItem* twiAmpl;
  QTableWidgetItem* twiZero;
  */
};

#endif /*PENDULUMVIEWER_H_*/
