#include "PendulumViewer.h"
#include <qwt_data.h>
#include <qwt_symbol.h>
#include <math.h>
#include <QBrush>
#include <QPen>
#include <qwt_plot_grid.h>
#include <QTableWidget>
#include <QTableWidgetItem>

PendulumViewer::PendulumViewer(QWidget *parent)
  : QWidget (parent)
{
  ui.setupUi (this);
  dataPlot = ui.qwtpShowPend;
  setWindowFlags (Qt::Popup | Qt::Dialog);
  //setAttribute (Qt::WA_DeleteOnClose, true);
  
  dataPlot -> setTitle (tr ("Колебания маятника"));
  
  dataCurve = new QwtPlotCurve ("Curve 1");
  dataCurve -> setStyle (QwtPlotCurve::NoCurve);
  QwtSymbol symbol (QwtSymbol::Ellipse, QBrush (Qt::blue), QPen (Qt::darkBlue), QSize (7, 7));
  dataCurve -> setSymbol (symbol);
  dataCurve -> attach (dataPlot);
  
  QwtPlotGrid* grid = new QwtPlotGrid ();
  grid -> enableXMin (true);
  grid -> enableYMin (true);
  grid -> setMajPen (QPen (Qt::black, 0, Qt::DotLine));
  grid -> setMinPen (QPen (Qt::gray, 0, Qt::DotLine));
  grid -> attach (dataPlot);
  
  dataPlot -> setAxisTitle (QwtPlot::xBottom, tr ("N"));
  dataPlot -> setAxisTitle (QwtPlot::yLeft, tr ("lg(A)"));
  
  //createTableWidgetItems ();
}

/*
void PendulumViewer::createTableWidgetItems ()
{
  QTableWidgetItem *newItem = 0;
  int row = 0;
  
  newItem = new QTableWidgetItem (tr("№"));
  ui.twShowPend -> setItem (row++, 0, newItem);
  
  newItem = new QTableWidgetItem(tr("Период, мс"));
  ui.twShowPend -> setItem (row++, 0, newItem);  
  
  newItem = new QTableWidgetItem(tr("Амплитуда"));
  ui.twShowPend -> setItem (row++, 0, newItem);  

  newItem = new QTableWidgetItem(tr("Ноль"));
  ui.twShowPend -> setItem (row++, 0, newItem);
  
  row = 0;
  twiNumber = new QTableWidgetItem (tr("0"));
  ui.twShowPend -> setItem (row++, 1, twiNumber);
  twiPeriod = new QTableWidgetItem (tr("0"));
  ui.twShowPend -> setItem (row++, 1, twiPeriod);
  twiAmpl = new QTableWidgetItem (tr("0"));
  ui.twShowPend -> setItem (row++, 1, twiAmpl);
  twiZero = new QTableWidgetItem (tr("0"));
  ui.twShowPend -> setItem (row++, 1, twiZero);
}
*/
void PendulumViewer::assign (PController* pController)
{
  QObject::connect(pController, SIGNAL(beginMeasurement ()),
                        this, SLOT(beginMeasurement ()));
  
  QObject::connect(pController, SIGNAL(endMeasurement (double, double, double)),
                        this, SLOT(endMeasurement (double, double, double)));

  QObject::connect(pController, SIGNAL(measurementReaded (int, double, double, double)),
                        this, SLOT(measurementReaded (int, double, double, double)));
  
  connect (ui.tbPause, SIGNAL(clicked(bool)), pController, SLOT (pause(bool)));
  
  connect (pController, SIGNAL(paused(bool)), ui.tbPause, SLOT (setChecked(bool)));
}

void PendulumViewer::beginMeasurement ()
{
  data.clear ();
  ui.lCoeffCorrel -> setText ("<font color='red'>" + ui.lCoeffCorrel -> text () + "</font>");
}

void PendulumViewer::endMeasurement (double period, double decrement, double correlation)
{
  ui.lCoeffCorrel -> setText (QString::number (correlation, 'g', 3));
  dataCurve -> setData (data);
  dataPlot -> replot ();
}

void PendulumViewer::measurementReaded (int number, double maxAmpl, double minAmpl, double period)
{ 
  ui.lNumber -> setText (QString::number (number));
  ui.lPeriod -> setText (QString::number (period * 1000.0));
  ui.lAmpl -> setText (QString::number (maxAmpl - minAmpl));
  ui.lZero -> setText (QString::number (maxAmpl + minAmpl));  
  
  data << QPointF (number, log (maxAmpl - minAmpl) / log (10.0) );
  if (isVisible ())
  {
    dataCurve -> setData (data);
    dataPlot -> replot ();
  }
}
