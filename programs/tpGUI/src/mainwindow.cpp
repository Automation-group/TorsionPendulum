#include <QMenuBar>
#include <QPen>
#include "mainwindow.h"
#include <qwt_legend.h> 
#include <qwt_plot_grid.h>
#include <qwt_plot_curve.h>
#include <qwt_symbol.h>
#include <qwt_plot_picker.h>

MainWindow::MainWindow (QWidget* parent)
  : QDialog (parent), isHeating (true)
{
  ui.setupUi (this);
  
  connect (ui.tbPendulumView, SIGNAL(clicked()), this, SIGNAL(showPendulumViewer ()));
  connect (ui.pbOscillograph, SIGNAL(clicked()), this, SIGNAL(showOscillograph()));
  connect (ui.cbCooling, SIGNAL(clicked(bool)), this, SLOT(onCoolingView(bool)));
  
  createPlotCurve ();
  createActions ();
  createMenus ();
  createToolBars ();
}

void MainWindow::assign (Experiment* experiment)
{
  connect (experiment, SIGNAL(dataReady (double, double, double, double, double)),
      this, SLOT(dataReady (double, double, double, double, double)));
  connect (ui.bStart, SIGNAL(clicked()), this, SLOT(onStart()));
  connect (ui.bStart, SIGNAL(clicked()), experiment, SLOT(start()));
  
  connect (ui.bStop, SIGNAL(clicked()), experiment, SLOT(stop()));
  connect (ui.bExit, SIGNAL(clicked()), experiment, SLOT(stop()));
  
  connect (ui.bPause, SIGNAL(clicked(bool)), experiment, SLOT(pause(bool)));
  connect (experiment, SIGNAL(paused(bool)), ui.bPause, SLOT(setChecked(bool)));
  
  connect (ui.tbSettings, SIGNAL(clicked()), this, SIGNAL(configurePendulum ()));
}

void MainWindow::onStart ()
{
  ui.bStart -> setEnabled (false);
  ui.bStop -> setEnabled (true);
  tempTimer.start ();
}

void MainWindow::on_vsCorell_valueChanged (int value)
{
  ui.lCorell -> setText(QString::number((double)value / 100.0, 'f', 3));
  updateDataPlots ();
}

void MainWindow::createPlotCurve ()
{
  ui.qwtpMainData -> enableAxis (QwtPlot::yRight);
  ui.qwtpMainData -> setAxisTitle (QwtPlot::xBottom, tr ("T,°C"));
  ui.qwtpMainData -> setAxisTitle (QwtPlot::yLeft, tr ("Q¯¹ x 1000"));
  ui.qwtpMainData -> setAxisTitle (QwtPlot::yRight, tr ("G, ГПа"));
  
  QwtLegend* legend = new QwtLegend (ui.qwtpMainData);
  legend -> setFrameStyle (QFrame::Box | QFrame::Sunken);
  ui.qwtpMainData -> insertLegend (legend, QwtPlot::TopLegend);
  
  QwtPlotGrid* grid = new QwtPlotGrid ();
  grid -> enableXMin (true);
  grid -> enableYMin (true);
  grid -> setMajPen (QPen (Qt::black, 0, Qt::DotLine));
  grid -> setMinPen (QPen (Qt::gray, 0, Qt::DotLine));
  grid -> attach (ui.qwtpMainData);
  
  pcDataHeatingQ = new QwtPlotCurve ( tr("Q¯¹(T) нагрев"));  
  QwtSymbol symbolHQ (QwtSymbol::Cross, QBrush (Qt::red), QPen (Qt::red), QSize (8, 8));
  pcDataHeatingQ -> setSymbol (symbolHQ);
  pcDataHeatingQ -> setPen (QPen(Qt::red));
  pcDataHeatingQ -> setYAxis (QwtPlot::yLeft);
  pcDataHeatingQ -> setRenderHint (QwtPlotItem::RenderAntialiased);
  pcDataHeatingQ -> attach (ui.qwtpMainData);

  pcDataCoolingQ = new QwtPlotCurve ( tr("Q¯¹(T) охлаждение"));  
  QwtSymbol symbolCQ (QwtSymbol::Cross, QBrush (Qt::blue), QPen (Qt::blue), QSize (8, 8));
  pcDataCoolingQ -> setSymbol (symbolCQ);
  pcDataCoolingQ -> setPen (QPen(Qt::blue));
  pcDataCoolingQ -> setYAxis (QwtPlot::yLeft);
  pcDataCoolingQ -> setRenderHint (QwtPlotItem::RenderAntialiased);
  pcDataCoolingQ -> attach (ui.qwtpMainData);

  pcDataHeatingG = new QwtPlotCurve ( tr("G(T) нагрев"));
  QwtSymbol symbolHG (QwtSymbol::XCross, QBrush (Qt::darkRed), QPen (Qt::darkRed), QSize (8, 8));
  pcDataHeatingG -> setSymbol (symbolHG);
  pcDataHeatingG -> setPen (QPen (Qt::darkRed));
  pcDataHeatingG -> setYAxis (QwtPlot::yRight);
  pcDataHeatingG -> setRenderHint (QwtPlotItem::RenderAntialiased);  
  pcDataHeatingG -> attach (ui.qwtpMainData);  
  
  pcDataCoolingG = new QwtPlotCurve ( tr("G(T) охлаждение"));
  QwtSymbol symbolCG (QwtSymbol::XCross, QBrush (Qt::darkBlue), QPen (Qt::darkBlue), QSize (8, 8));
  pcDataCoolingG -> setSymbol (symbolCG);
  pcDataCoolingG -> setPen (QPen (Qt::darkBlue));
  pcDataCoolingG -> setYAxis (QwtPlot::yRight);
  pcDataCoolingG -> setRenderHint (QwtPlotItem::RenderAntialiased);  
  pcDataCoolingG -> attach (ui.qwtpMainData);

  pcDataT = new QwtPlotCurve ( tr("T(t)"));    
  QwtSymbol symbolT (QwtSymbol::XCross, QBrush (Qt::blue), QPen (Qt::blue), QSize (8, 8));
  pcDataT -> setSymbol (symbolT);
  pcDataT -> setPen (QPen (Qt::blue));
  pcDataT -> setRenderHint (QwtPlotItem::RenderAntialiased);  
  pcDataT -> attach (ui.qwtpTemperature);
  
  grid = new QwtPlotGrid ();
  grid -> enableXMin (true);
  grid -> enableYMin (true);
  grid -> setMajPen (QPen (Qt::black, 0, Qt::DotLine));
  grid -> setMinPen (QPen (Qt::gray, 0, Qt::DotLine));
  grid -> attach (ui.qwtpTemperature);
  
  ui.qwtpTemperature -> setAxisTitle (QwtPlot::xBottom, tr ("t, мин"));
  ui.qwtpTemperature -> setAxisTitle (QwtPlot::yLeft, tr ("T, °C"));
  
  ui.qwtpMainData -> setAutoReplot (true);
  ui.qwtpTemperature -> setAutoReplot (true);

  QwtPlotPicker* pickerQ = new QwtPlotPicker (QwtPlot::xBottom, QwtPlot::yLeft, 
      QwtPicker::PointSelection | QwtPicker::DragSelection,
      QwtPlotPicker::CrossRubberBand, QwtPicker::AlwaysOn,
      ui.qwtpMainData -> canvas ()); 
}

void MainWindow::createToolBars ()
{
  
}

void MainWindow::createMenus ()
{
  //QMenu* menu = menuBar () -> addMenu (tr ("Configure"));
  //menu -> addAction (aConfigure);
}

void MainWindow::createActions ()
{
}

void MainWindow::temperatureReady (double temperature, double speed)
{
  double time = tempTimer.elapsed () / 1000.0 / 60.0;
  if ( dataT.isEmpty () || ((time - dataT.last (). x()) > 0.25))
  {
    ui.lTemperature -> setText (QString::number ((int)temperature));
    ui.lHeatingSpeed -> setText (QString::number (speed, 'f', 1));
    dataT << QPointF (time, temperature);
    pcDataT -> setData (dataT);
  }
  
  //if (speed < -0.5) isHeating = false;
}

void MainWindow::onCoolingView (bool value)
{
  isHeating = ! value;
}

void MainWindow::updateDataPlots ()
{
  const double R = ui.vsCorell -> value() / 100.0;

  QwtPlotCurve* pcG = isHeating ? pcDataHeatingG : pcDataCoolingG;
  QwtPlotCurve* pcQ = isHeating ? pcDataHeatingQ : pcDataCoolingQ;
  QPolygonF dataQ = isHeating ? dataHeatingQ : dataCoolingQ;
  QPolygonF dataG = isHeating ? dataHeatingG : dataCoolingG;
  
  QVector<double> dataR = isHeating ? dataHeatingR : dataCoolingR;
    
  QPolygonF::iterator iG = dataG.begin();
  QPolygonF::iterator iQ = dataQ.begin();
  QVector<double>::iterator iR = dataR.begin();
    
  while(iG != dataG.end())
  {  
    if (*iR >= R)
    {
      ++iG;  ++iQ; ++iR;
      continue;
    }
    
    iG = dataG.erase(iG);
    iQ = dataQ.erase(iQ);    
    iR = dataR.erase(iR);
  }
  
  pcG -> setData (dataG);
  pcQ -> setData (dataQ);  
}

void MainWindow::dataReady (double G, double Q, double R, double T, double period)
{
  qDebug ("Data ready ok");
  if (isHeating)
  {
    dataHeatingG << QPointF (T, G / 1e9);
    dataHeatingQ << QPointF (T, Q * 1000.0);
    dataHeatingR.push_back(R);    
  }
  else
  {
    dataCoolingG << QPointF (T, G / 1e9);
    dataCoolingQ << QPointF (T, Q * 1000.0);    
    dataCoolingR.push_back(R);    
  }
  
  updateDataPlots ();
}

void MainWindow::setPatternInfo (const Pattern& pattern)
{
  ui.lPatternWidth -> setText (QString::number (pattern.width () * 1000.0, 'g', 3)); 
  ui.lPatternThickness -> setText (QString::number (pattern.thickness () * 1000.0, 'g', 3));
  ui.lPatternLenght -> setText (QString::number (pattern.height () * 1000.0, 'g', 3));
}

void MainWindow::setPendulumInfo (const Pendulum& pendulum)
{
  ui.lPendulumM1 -> setText (QString::number (pendulum.getM1 () * 1000.0, 'g', 3)); 
  ui.lPendulumM2 -> setText (QString::number (pendulum.getM2 () * 1000.0, 'g', 3));
  ui.lPendulumR -> setText (QString::number (pendulum.getR1 () * 1000.0, 'g', 3));
  ui.lPendulumKb -> setText (QString::number (pendulum.getKb (), 'g', 3));  
}

void MainWindow::powerReady (double power)
{
  ui.lMetakonPower -> setText (QString::number ((int)(power * 100.0)));
}
