#include "ExpConfigDialog.h"
#include "tpGlobal.h"
#include <QtDebug>

ExpConfigDialog::ExpConfigDialog ()
  : QDialog ()
{
  ui.setupUi (this);
  connect (ui.pbOk, SIGNAL(clicked ()), this, SLOT(onOk ()));
  loadDialog ();
}

void ExpConfigDialog::saveDialog ()
{
  tpSettings ().beginGroup (tr("Эксперимет-StartDialog"));    
  tpSettings ().setValue( tr("FluctCount"), ui.sbFluctCount -> value ());
  tpSettings ().setValue( tr("DeviationTime"), ui.sbDeviationTime -> value ());
  tpSettings ().setValue( tr("FluctMinAmpl"), ui.dsbFluctMinAmpl -> value ());
  tpSettings ().setValue( tr("SkipFluctCount"), ui.sbSkipFluctCount -> value ());  
  tpSettings ().setValue( tr("ZeroControl"), ui.cbZeroControl -> isChecked ());  
  tpSettings ().setValue( tr("sbHeatingSpeed"), ui.sbHeatingSpeed -> value ());
  tpSettings ().setValue( tr("sbMaxTemperature"), ui.sbMaxTemperature -> value ());
  tpSettings ().endGroup ();
}

void ExpConfigDialog::loadDialog ()
{
  tpSettings ().beginGroup (tr("Эксперимет-StartDialog"));
  ui.sbFluctCount -> setValue (tpSettings ().value (tr("FluctCount")).toInt ());
  ui.sbDeviationTime -> setValue (tpSettings ().value(tr("DeviationTime")).toInt ());
  ui.dsbFluctMinAmpl -> setValue (tpSettings ().value(tr("FluctMinAmpl")).toDouble ());
  ui.sbSkipFluctCount -> setValue (tpSettings ().value(tr("SkipFluctCount")).toInt ());
  ui.cbZeroControl -> setChecked (tpSettings ().value(tr("ZeroControl")).toBool ());
  ui.sbHeatingSpeed -> setValue (tpSettings ().value(tr("sbHeatingSpeed")) .toInt ());
  ui.sbMaxTemperature -> setValue (tpSettings ().value(tr("sbMaxTemperature")) .toInt ());
  tpSettings ().endGroup ();  
}

void ExpConfigDialog::applaySettings ()
{
  setFluctCount (ui.sbFluctCount -> value ());
  setDeviationTime (ui.sbDeviationTime -> value ());
  setFluctMinAmpl (ui.dsbFluctMinAmpl -> value ());
  setSkipFluctCount (ui.sbSkipFluctCount -> value ());
  zeroControl (ui.cbZeroControl -> isChecked ());
  setHeatingSpeed (ui.sbHeatingSpeed -> value ());
  setMaxTemperature (ui.sbMaxTemperature -> value ());
}

void ExpConfigDialog::onOk ()
{ 
  saveDialog ();
  applaySettings ();
  setResult (QDialog::Accepted);
  close ();
}
