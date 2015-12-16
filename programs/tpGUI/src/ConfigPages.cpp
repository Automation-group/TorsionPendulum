#include <QtGui>
#include "tpGlobal.h"
#include "ConfigPages.h"
#include <qextserialport.h>

MetakonConfigPage::MetakonConfigPage (QWidget*parent)
  :QWidget (parent)
{
  ui.setupUi (this);
  ui.cbBaudRate -> addItem (tr ("19200 Bit/s"), (int)BAUD19200);
  ui.cbBaudRate -> addItem (tr ("9600 Bit/s"), (int)BAUD9600);
  ui.cbBaudRate -> addItem (tr ("4800 Bit/s"), (int)BAUD4800);
  ui.cbBaudRate -> addItem (tr ("2400 Bit/s"), (int)BAUD2400);
  
  loadSettings ();
}

void MetakonConfigPage::saveSettings ()
{
  tpSettings ().beginGroup (tr("МЕТАКОН"));    
  tpSettings ().setValue( tr("PortName"), ui.leSerialPortName -> text ());
  tpSettings ().setValue( tr("DevAddress"), ui.sbDevAddress -> value ());
  tpSettings ().setValue( tr("Channel"), ui.sbChannel -> value ());
  tpSettings ().setValue( tr("Integr"), ui.sbIntegr -> value ());  
  tpSettings ().setValue( tr("Diff"), ui.sbDiff -> value ());
  tpSettings ().setValue( tr("Pb"), ui.sbPb -> value ());
  tpSettings ().setValue( tr("BaudRate"), ui.cbBaudRate -> itemData (ui.cbBaudRate -> currentIndex ()));  
  tpSettings ().endGroup ();
}

void MetakonConfigPage::loadSettings ()
{
  tpSettings ().beginGroup (tr("МЕТАКОН"));
  ui.leSerialPortName -> setText (tpSettings ().value (tr("PortName")).toString ());
  ui.sbDevAddress -> setValue (tpSettings ().value(tr("DevAddress")).toInt ());
  ui.sbChannel -> setValue (tpSettings ().value(tr("Channel")).toInt ());
  ui.sbIntegr -> setValue (tpSettings ().value(tr("Integr")).toInt ());
  ui.sbDiff -> setValue (tpSettings ().value(tr("Diff")).toInt ());
  ui.sbPb -> setValue (tpSettings ().value(tr("Pb")).toInt ());
  
  int index = ui.cbBaudRate -> findData (tpSettings ().value (tr("BaudRate")));
  ui.cbBaudRate -> setCurrentIndex (index);
  tpSettings ().endGroup ();  
}

TornPendConfigPage::TornPendConfigPage (QWidget *parent)
  : QWidget (parent)
{
  ui.setupUi (this);
  loadSettings ();
}

void TornPendConfigPage::saveSettings ()
{
  tpSettings ().beginGroup (tr("КРУТИЛЬНЫЙ_МАЯТНИК"));    
  tpSettings ().setValue( tr("PortName"), ui.leSerialPortName -> text ());
  tpSettings ().setValue( tr("Kb"), ui.dsbKb -> value ());
  tpSettings ().setValue( tr("Jp"), ui.dsbJp -> value () * 1e-6);
  tpSettings ().setValue( tr("Qp"), ui.dsbQp -> value () * 1e-3);  
  tpSettings ().endGroup ();
}

void TornPendConfigPage::loadSettings ()
{
  tpSettings ().beginGroup (tr("КРУТИЛЬНЫЙ_МАЯТНИК"));
  ui.leSerialPortName -> setText (tpSettings ().value (tr("PortName")).toString ());
  ui.dsbKb -> setValue (tpSettings ().value(tr("Kb")).toDouble ());
  ui.dsbJp -> setValue (tpSettings ().value(tr("Jp")).toDouble () * 1e6);
  ui.dsbQp -> setValue (tpSettings ().value(tr("Qp")).toDouble () * 1e3);
  tpSettings ().endGroup ();  
}
