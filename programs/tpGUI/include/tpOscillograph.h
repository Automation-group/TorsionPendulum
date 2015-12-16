#ifndef TPOSCILLOGRAPH_H_
#define TPOSCILLOGRAPH_H_

#include <QDialog>
#include <QPolygonF>
#include "ui_tposcillographDialog.h"
#include <qwt_plot_curve.h>
#include <QTime>

class TPOscillograph: public QDialog
{
  Q_OBJECT
public:
  TPOscillograph ();
public slots:
  void adcReady (int code);
signals:
  void startADC ();
  void stopADC ();
  void setResistorCode (int code = 127);
private:
  QTime time;
  QwtPlotCurve *dataCurve;
  QPolygonF data;
  Ui_TPOscillographDialog ui;
};

#endif /*TPOSCILLOGRAPH_H_*/
