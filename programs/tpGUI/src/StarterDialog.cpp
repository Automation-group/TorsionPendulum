#include "StarterDialog.h"
#include "tpGlobal.h"
#include "ConfigDialog.h"
#include "CalibrateFurnace.h"
#include <QFile>
#include "StartDialog.h"
#include "Experiment.h"
#include "ExpTextFileWriter.h"

#include "mainwindow.h"
#include "PendulumViewer.h"
#include "ExpConfigDialog.h"
#include "ResCalibrateDialog.h"
#include "tpOscillograph.h"
#include "SoundInformator.h"
#include <QMessageBox>
#include "TextInformant.h"
#include <QDockWidget>

StarterDialog::StarterDialog ()
  : QDialog ()
{
  ui.setupUi (this);
  createSerialPorts ();
  
  createControllers ();
  createInformants ();
  
  connect (ui.pbSettings, SIGNAL (clicked()), this, SLOT(configure()));
  connect (ui.pbCalibrateFurnace, SIGNAL (clicked()), this, SLOT(calibrateFurnace()));
  connect (ui.pbStart, SIGNAL (clicked()), this, SLOT(startExperiment()));
}
StarterDialog::~StarterDialog ()
{
  
}

void StarterDialog::createControllers ()
{
  rNet = new QlfRNet (rnetSPort);
  tController = new TController (rNet);
  
  tornPend = new QlfTornPend (tpSPort); 
  tornPend -> stop ();
  tornPend -> setResistorCode (127);
  
  pController = new PController (tornPend);
}

void StarterDialog::createSerialPorts ()
{
  rnetSPort = new QextSerialPort ("/dev/ttyS0");
  tpSPort = new QextSerialPort ("/dev/ttyUSB0");  
}

bool StarterDialog::openSerialPorts ()
{
  tpSettings ().beginGroup (QObject::tr("МЕТАКОН"));
  rnetSPort -> setPortName (tpSettings ().value (QObject::tr("PortName"), "/dev/ttyS0").toString ());
  rnetSPort -> setBaudRate ( (BaudRateType)tpSettings ().value (QObject::tr("BaudRate"), BAUD19200).toInt ());
  tpSettings ().endGroup ();
  
  rnetSPort -> setDataBits (DATA_8);
  rnetSPort -> setParity (PAR_NONE);
  rnetSPort -> setStopBits (STOP_1);
  rnetSPort -> setFlowControl (FLOW_HARDWARE);
  rnetSPort -> setTimeout (0, 500);
  

  tpSettings ().beginGroup (QObject::tr("КРУТИЛЬНЫЙ_МАЯТНИК"));
  tpSPort -> setPortName  (tpSettings ().value (QObject::tr("PortName"), "/dev/ttyUSB0").toString ());
  tpSettings ().endGroup ();
 
  tpSPort -> setBaudRate (BAUD115200);
  tpSPort -> setDataBits (DATA_8);
  tpSPort -> setParity (PAR_NONE);
  tpSPort -> setStopBits (STOP_2);
  tpSPort -> setFlowControl (FLOW_HARDWARE);
  tpSPort -> setTimeout (0, 500);
  
  rnetSPort -> open (QIODevice::ReadWrite | QIODevice::Unbuffered);
  tpSPort -> open (QIODevice::ReadWrite | QIODevice::Unbuffered);
  
  return rnetSPort -> isOpen () && tpSPort -> isOpen ();  
}

void StarterDialog::closeSerialPorts ()
{
  rnetSPort -> close ();
  tpSPort -> close ();  
}

void StarterDialog::createInformants ()
{
  
}

void StarterDialog::connectInformant (QObject* informant)
{
  connect(pController, SIGNAL(disconnected ()), informant, SLOT(pendulumDisconnected ()));
  connect(pController, SIGNAL(zeroControlFailed ()), informant, SLOT(zeroControlFailed ()));
  connect(pController, SIGNAL(zeroWarning ()), informant, SLOT(zeroWarning ()));
  connect(pController, SIGNAL(bigAmplitude ()), informant, SLOT(bigAmplitude ()));
  connect(pController, SIGNAL(smallAmplitude ()), informant, SLOT(smallAmplitude ()));
  connect(pController, SIGNAL(deviationFailed ()), informant, SLOT(deviationFailed ()));
  connect(pController, SIGNAL(beginMeasurement ()), informant, SLOT(beginMeasurement ()));
  
  connect(tController, SIGNAL(disconnected ()), informant, SLOT(metakonDisconnected ()));
  
  connect(tController, SIGNAL(temperatureRead (double, double)), 
      informant, SLOT(temperatureRead (double, double)));  
}

void StarterDialog::setDefaultPID ()
{
  tpSettings ().beginGroup (QObject::tr("МЕТАКОН"));
  tController -> setPID ( tpSettings ().value(QObject::tr("Integr")).toInt (),
      tpSettings ().value(QObject::tr("Diff")).toInt (),
      tpSettings ().value(QObject::tr("Pb")).toInt ());
  tpSettings ().endGroup ();    
}

void StarterDialog::showSerialPortErrors ()
{
  if (! rnetSPort -> isOpen ())
    QMessageBox::critical (this, tr("МЕТАКОН"), tr("Не могу открыть порт.\n") + rnetSPort -> errorString ());
  
  if (! tpSPort -> isOpen ())
    QMessageBox::critical (this, tr("Крутильный маятник"), tr("Не могу открыть порт.\n") + tpSPort -> errorString ());
}

void StarterDialog::startExperiment ()
{
  if (!openSerialPorts ())
  {
    showSerialPortErrors ();
    closeSerialPorts ();
    configure ();
    return;
  }
  
  tornPend -> stop ();
  tornPend -> setResistorCode (127);
  
  StartDialog startDialog;
  startDialog.exec ();
  if (QDialog::Accepted != startDialog.result ()) return;
  
  QFile expFile (startDialog.getExpFileName ());
  expFile.open (QIODevice::WriteOnly);
  ExpTextFileWriter expTextFileWriter (&expFile);
  
  setDefaultPID ();
  
  Experiment experiment (pController, tController);  
  QObject::connect (&experiment, SIGNAL(dataReady (double, double, double, double, double)),
      &expTextFileWriter, SLOT(dataReady (double, double, double, double, double)));  
  experiment.setPendulum (startDialog.getPendulum ());
  experiment.setPattern (startDialog.getPattern ());  

  /** Осциллограф */ 
  TPOscillograph oscillograph;
  QObject::connect (&oscillograph, SIGNAL(startADC ()), tornPend, SLOT(runADC ()));
  QObject::connect (&oscillograph, SIGNAL(stopADC ()), tornPend, SLOT(stopADC ()));
  QObject::connect (tornPend, SIGNAL(adcCodeReaded (int)), &oscillograph, SLOT(adcReady (int)));  
  QObject::connect (&oscillograph, SIGNAL(setResistorCode (int)), tornPend, SLOT(setResistorCode (int)));  
  /** конец Осцилограф*/  
  
  ExpConfigDialog expConfigDialog; 
  QObject::connect (&expConfigDialog, SIGNAL(setFluctCount (int)), pController, SLOT(setFluctCount (int)));
  QObject::connect (&expConfigDialog, SIGNAL(setDeviationTime (int)), pController, SLOT(setDeviationTime (int)));
  QObject::connect (&expConfigDialog, SIGNAL(setFluctMinAmpl (double)), pController, SLOT(setFluctMinAmpl (double)));
  QObject::connect (&expConfigDialog, SIGNAL(setSkipFluctCount (int)), pController, SLOT(setSkipFluctCount (int)));
  QObject::connect (&expConfigDialog, SIGNAL(zeroControl (bool)), pController, SLOT(zeroControl (bool)));
  QObject::connect (&expConfigDialog, SIGNAL(setHeatingSpeed (int) ), tController, SLOT(setHeatingSpeed (int)));
  
  PendulumViewer pendViewer;
  pendViewer.assign (pController);
  
  /*
  SoundInformator soundInformator;
  connectInformant (&soundInformator);
  connect(&expConfigDialog, SIGNAL(setMaxTemperature (int)), 
      &soundInformator, SLOT(setMaxTemperature (int)));  
  */
  
  TextInformant textInformant;
  connectInformant (&textInformant);
  /*
  connect(&textInformant, SIGNAL(setMaxTemperature (int)), 
      &soundInformator, SLOT(setMaxTemperature (int)));
      */  
  
  expConfigDialog.applaySettings ();
  
  MainWindow* mw = new MainWindow ();
  
  mw -> assign (&experiment);
  QObject::connect (mw, SIGNAL(configurePendulum ()), &expConfigDialog, SLOT(exec ()));
  
  QObject::connect (mw, SIGNAL(showPendulumViewer ()), &pendViewer, SLOT(show ()));
  QObject::connect (tController, SIGNAL(temperatureRead (double, double)),
      mw, SLOT(temperatureReady(double, double)));
  QObject::connect (tController, SIGNAL(powerRead (double)),
        mw, SLOT(powerReady(double)));
      
  QObject::connect (mw, SIGNAL(showOscillograph ()), &oscillograph, SLOT(show ()));
  
  mw -> setPatternInfo (startDialog.getPattern ());
  mw -> setPendulumInfo (startDialog.getPendulum ());
  
  hide ();
  
  mw -> showMaximized ();
  mw -> exec ();
  delete mw;
  show ();
  closeSerialPorts ();
}

void StarterDialog::configure ()
{
  hide ();
  ConfigDialog configDialog;
  configDialog.exec ();
  show ();
}

void StarterDialog::calibrateFurnace ()
{
  openSerialPorts ();
  tController -> setPID (30000, 0, 1);
  CalibrateFurnace calibrateFurnace;
  QObject::connect (&calibrateFurnace, SIGNAL(setPoint (int) ), tController, SLOT(setPoint (int)));
  QObject::connect (&calibrateFurnace, SIGNAL(start () ), tController, SLOT(startMeasurements ()));
  QObject::connect (&calibrateFurnace, SIGNAL(stop () ), tController, SLOT(stopMeasurements ()));
  QObject::connect (tController, SIGNAL(temperatureRead (double, double)),&calibrateFurnace, SLOT (temperatureRead (double, double)));
  hide ();
  calibrateFurnace.exec ();
  show ();
  closeSerialPorts ();
}
