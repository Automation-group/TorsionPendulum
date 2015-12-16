#include "tpOscillograph.h"
#include <qwt_symbol.h>
#include <qwt_plot_grid.h>
#include <qwt_plot_picker.h>
#include <qwt_plot_marker.h>

TPOscillograph::TPOscillograph ()
{
  ui.setupUi (this);
  setWindowFlags (Qt::Popup | Qt::Dialog);
  
  ui.qwtpOscillograph -> setTitle (tr ("Колебания маятника"));
  
  ui.qwtpOscillograph -> setTitle (tr ("Осциллограф"));
  
  dataCurve = new QwtPlotCurve ("Осциллограф");
  dataCurve -> setStyle (QwtPlotCurve::Lines);
  dataCurve -> setPen ( QPen (QColor (10, 255, 45)));
  dataCurve -> attach (ui.qwtpOscillograph);
  
  QwtPlotGrid* grid = new QwtPlotGrid ();
  grid -> enableXMin (true);
  grid -> enableYMin (true);
  grid -> setMajPen (QPen (Qt::darkGreen, 0, Qt::DotLine));
  grid -> setMinPen (QPen (Qt::darkGreen, 0, Qt::NoPen));
  grid -> attach (ui.qwtpOscillograph);
  
  ui.qwtpOscillograph -> setAxisTitle (QwtPlot::xBottom, tr ("t,сек"));
  ui.qwtpOscillograph -> setAxisTitle (QwtPlot::yLeft, tr (""));
  ui.qwtpOscillograph -> setAxisScale (QwtPlot::yLeft, -5.2, 5.2, 1.0);
  ui.qwtpOscillograph -> setAxisScale (QwtPlot::xBottom, 0, 1.0, 0.1);
  
  connect (ui.pbStart, SIGNAL(clicked()), this, SIGNAL(startADC()));
  connect (ui.pbStop, SIGNAL(clicked()), this, SIGNAL(stopADC()));
  connect (ui.pbClearResistor, SIGNAL(clicked()), this, SIGNAL(setResistorCode ()));
  
  ui.qwtpOscillograph -> setAutoReplot (true);
  ui.qwtpOscillograph -> setCanvasBackground (Qt::black);
  data.reserve (2000);
  
  QwtPlotPicker* picker = new QwtPlotPicker (QwtPlot::xBottom, QwtPlot::yLeft, 
      QwtPicker::PointSelection | QwtPicker::DragSelection,
      QwtPlotPicker::CrossRubberBand, QwtPicker::AlwaysOn,
      ui.qwtpOscillograph -> canvas ());
  picker -> setRubberBandPen (QColor (Qt::white));
  picker -> setTrackerPen ( QColor (Qt::white));
  
  QwtPlotMarker* marker = new QwtPlotMarker ();
  //marker -> setValue (0.0, 0.0)
  marker -> setLineStyle (QwtPlotMarker::HLine);
  marker -> setLinePen (QPen (Qt::yellow, 0, Qt::SolidLine));
  marker -> attach (ui.qwtpOscillograph);
  
  time.start ();
}

void TPOscillograph::adcReady (int code)
{
  //qDebug ("AR%i", code);
  if (data.isEmpty ()) time.restart ();
  data << QPointF (time.elapsed () / 1000.0, code / 100.0);
  
  if (time.elapsed () > 1000)
  //if (data.size () > 300)
  {
    dataCurve -> setData (data);
    data.clear ();
    //data.reserve (2000);
    //time.restart ();
  }
}
