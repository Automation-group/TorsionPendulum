#include "CalibrateFurnace.h"
#include <qwt_plot_grid.h>
#include <qwt_data.h>
#include <qwt_symbol.h>
#include <QtGlobal>

CalibrateFurnace::CalibrateFurnace ()
  : QDialog ()
{
  ui.setupUi (this);
  connect (ui.pbStart, SIGNAL(clicked ()), this, SLOT(onStart()));
  connect (ui.pbStart, SIGNAL(clicked ()), this, SIGNAL(start()));
  connect (ui.pbStop, SIGNAL(clicked ()), this, SIGNAL(stop()));
  
  ui.qwtpData -> setAutoReplot (true);
  
  ui.qwtpData -> setTitle (tr ("Температура"));
  
  dataCurve = new QwtPlotCurve ("T(t)");
  dataCurve -> setStyle (QwtPlotCurve::NoCurve);
  QwtSymbol symbol (QwtSymbol::Ellipse, QBrush (Qt::blue), QPen (Qt::darkBlue), QSize (7, 7));
  dataCurve -> setSymbol (symbol);
  dataCurve -> attach (ui.qwtpData);
  
  QwtPlotGrid* grid = new QwtPlotGrid ();
  grid -> enableXMin (true);
  grid -> enableYMin (true);
  grid -> setMajPen (QPen (Qt::black, 0, Qt::DotLine));
  grid -> setMinPen (QPen (Qt::gray, 0, Qt::DotLine));
  grid -> attach (ui.qwtpData);
  
  ui.qwtpData -> setAxisTitle (QwtPlot::xBottom, tr ("t, мин"));
  ui.qwtpData -> setAxisTitle (QwtPlot::yLeft, tr ("T, °C"));  
}

void CalibrateFurnace::temperatureRead (double temperature, double speed)
{
  maxTemperature = qMax (maxTemperature, temperature);
  static QTime pidTimer;
  static bool flag = false;
  if (setPointFlag && _setPoint < temperature)
  {
    pidTimer.start ();
    setPointFlag = false;
    flag = true;
  }
  
  if (flag && !setPointFlag && _setPoint > temperature)
  {
    ui.lTIntegr -> setText (QString::number (pidTimer.elapsed () / 1000));
    ui.lTDiff -> setText (QString::number ( (2 * pidTimer.elapsed ()) / 10000));
    ui.lPb -> setText (QString::number ((int)(maxTemperature - _setPoint)));
    flag = false;
  }
  
  data << QPointF (startTime.elapsed () / 1000.0 / 60.0, temperature);
  dataCurve -> setData (data);
}

void CalibrateFurnace::onStart ()
{
  maxTemperature = 0;
  setPointFlag = true;
  _setPoint = ui.sbSetPoint -> value ();
  startTime.start ();
  data.clear ();
  setPoint (_setPoint);
  ui.lTIntegr -> setText ("?");
  ui.lTDiff -> setText ("?");
  ui.lPb -> setText ("?");
}
