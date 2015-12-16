#include <QApplication>
#include <QTextCodec>
#include <QDialog>
#include "StarterDialog.h"

/*
QextSerialPort rnetSPort ("/dev/ttyS0");
QextSerialPort tpSPort ("/dev/ttyUSB0");

void connectInformator (QObject* informator, QObject* pController,
    QObject* tController, QObject* experiment, QObject* tempSettings)
{
  QObject::connect(pController, SIGNAL(disconnected ()), informator, SLOT(pendulumDisconnected ()));
  QObject::connect(pController, SIGNAL(zeroControlFailed ()), informator, SLOT(zeroControlFailed ()));
  QObject::connect(pController, SIGNAL(zeroWarning ()), informator, SLOT(zeroWarning ()));
  QObject::connect(pController, SIGNAL(bigAmplitude ()), informator, SLOT(bigAmplitude ()));
  QObject::connect(pController, SIGNAL(smallAmplitude ()), informator, SLOT(smallAmplitude ()));
  QObject::connect(pController, SIGNAL(deviationFailed ()), informator, SLOT(deviationFailed ()));
  QObject::connect(pController, SIGNAL(beginMeasurement ()), informator, SLOT(beginMeasurement ()));
  
  QObject::connect(tController, SIGNAL(temperatureRead (double, double)), 
      informator, SLOT(temperatureRead (double, double)));
  
  QObject::connect(tempSettings, SIGNAL(setMaxTemperature (int)), 
      informator, SLOT(setMaxTemperature (int)));  
}
*/

int main (int argc, char *argv[])
{
  QApplication app (argc, argv);
  QTextCodec::setCodecForTr(QTextCodec::codecForName("UTF-8"));
  
  StarterDialog starterDialog;
  starterDialog.show ();

  //qDebug () << "res" << result.toString ();
  
  /* Scripts */
  //QScriptEngine scriptEngine;
  //qDebug () << app.applicationDirPath ();
  //qDebug () << scriptEngine.evaluate ("MessageBox.information(\"Hello World\")", app.applicationDirPath () + "/scripts/init.js").toInt32 ();
  /* end scripts*/
  
  /*
  ConfigDialog configDialog;
  configDialog.exec ();
  
  tpSettings ().beginGroup (QObject::tr("МЕТАКОН"));
  rnetSPort.setPortName (tpSettings ().value (QObject::tr("PortName"), "/dev/ttyS0").toString ());
  rnetSPort.setBaudRate ( (BaudRateType)tpSettings ().value (QObject::tr("BaudRate"), BAUD19200).toInt ());
  tpSettings ().endGroup ();  
  
  tpSettings ().beginGroup (QObject::tr("КРУТИЛЬНЫЙ_МАЯТНИК"));
  tpSPort.setPortName  (tpSettings ().value (QObject::tr("PortName"), "/dev/ttyUSB0").toString ());
  tpSettings ().endGroup ();   
  
  rnetSPort.setDataBits (DATA_8);
  rnetSPort.setParity (PAR_NONE);
  rnetSPort.setStopBits (STOP_1);
  rnetSPort.setFlowControl (FLOW_HARDWARE);
  rnetSPort.setTimeout (0, 500);
  rnetSPort.open (QIODevice::ReadWrite | QIODevice::Unbuffered);
 
  tpSPort.setBaudRate (BAUD115200);
  tpSPort.setDataBits (DATA_8);
  tpSPort.setParity (PAR_NONE);
  tpSPort.setStopBits (STOP_2);
  tpSPort.setFlowControl (FLOW_HARDWARE);
  tpSPort.setTimeout (0, 500);
  tpSPort.open (QIODevice::ReadWrite | QIODevice::Unbuffered);  
  
  if ( ! rnetSPort.isOpen () )
    return 0;

  QlfRNet rnet (&rnetSPort);
    
  TController tController (&rnet);
  tController.setMaxPower (20);
  
  
  StartDialog startDialog;
  startDialog.exec ();
  if (QDialog::Accepted != startDialog.result ())
    return 0;  

  QFile expFile (startDialog.getExpFileName ());
  expFile.open (QIODevice::ReadWrite);
  ExpTextFileWriter expTextFileWriter (&expFile);
  
  tpSettings ().beginGroup (QObject::tr("МЕТАКОН"));
  tController.setPID ( tpSettings ().value(QObject::tr("Integr")).toInt (),
      tpSettings ().value(QObject::tr("Diff")).toInt ());
  tpSettings ().endGroup ();  
  
  */
  /** Калибровка печи 
  CalibrateFurnace calibrateFurnace;
  QObject::connect (&calibrateFurnace, SIGNAL(setPoint (int) ), &tController, SLOT(setPoint (int)));
  QObject::connect (&calibrateFurnace, SIGNAL(start () ), &tController, SLOT(startMeasurements ()));
  QObject::connect (&calibrateFurnace, SIGNAL(stop () ), &tController, SLOT(stopMeasurements ()));
  QObject::connect (&tController, SIGNAL(temperatureRead (double, double)),&calibrateFurnace, SLOT (temperatureRead (double, double)));
  calibrateFurnace.exec ();
  /** конец Калибровка печи */

  /*
  TPSimulator simulator;
  TPDevice tpDevice (&simulator);
  tpDevice.open (QIODevice::ReadWrite | QIODevice::Unbuffered);
  QlfTornPend tp (&tpDevice);
  */
  /*
  if ( ! tpSPort.isOpen () )
    return 0;

  QlfTornPend tp (&tpSPort); 
  tp.stop ();
  tp.setResistorCode (127);
  
  PController pend (&tp);
     
  Experiment experiment (&pend, &tController);  
  QObject::connect (&experiment, SIGNAL(dataReady (double, double, double, double)),
      &expTextFileWriter, SLOT(dataReady (double, double, double, double)));  
  experiment.setPendulum (startDialog.getPendulum ());
  experiment.setPattern (startDialog.getPattern ());  
  */
  /*
  ResCalibrateDialog resCalibrateDialog;
  QObject::connect (&resCalibrateDialog, SIGNAL(runPend ()), &tp, SLOT(run ()));
  QObject::connect (&resCalibrateDialog, SIGNAL(stopPend ()), &tp, SLOT(stop ()));
  QObject::connect (&resCalibrateDialog, SIGNAL(enableMagnet ()), &tp, SLOT(enableMagnet ()));
  QObject::connect (&resCalibrateDialog, SIGNAL(disableMagnet ()), &tp, SLOT(disableMagnet ()));  
  QObject::connect (&resCalibrateDialog, SIGNAL(setResistor (int)), &tp, SLOT(setResistorCode (int)));
  QObject::connect (&tp, SIGNAL(periodDataReaded (int, int, int, int)), &resCalibrateDialog, SLOT(periodDataReaded (int, int, int, int)));
  
  resCalibrateDialog.exec ();
  return 0;
  */
  
  /** Осциллограф 
  TPOscillograph oscillograph;
  QObject::connect (&oscillograph, SIGNAL(startADC ()), &tp, SLOT(runADC ()));
  QObject::connect (&oscillograph, SIGNAL(stopADC ()), &tp, SLOT(stopADC ()));
  QObject::connect (&tp, SIGNAL(adcCodeReaded (int)), &oscillograph, SLOT(adcReady (int)));  
  QObject::connect (&oscillograph, SIGNAL(setResistorCode (int)), &tp, SLOT(setResistorCode (int)));  
  /** конец Осцилограф*/  
  
  /*
  ExpConfigDialog expConfigDialog; 
  QObject::connect (&expConfigDialog, SIGNAL(setFluctCount (int)), &pend, SLOT(setFluctCount (int)));
  QObject::connect (&expConfigDialog, SIGNAL(setDeviationTime (int)), &pend, SLOT(setDeviationTime (int)));
  QObject::connect (&expConfigDialog, SIGNAL(setFluctMinAmpl (double)), &pend, SLOT(setFluctMinAmpl (double)));
  QObject::connect (&expConfigDialog, SIGNAL(setSkipFluctCount (int)), &pend, SLOT(setSkipFluctCount (int)));
  QObject::connect (&expConfigDialog, SIGNAL(zeroControl (bool)), &pend, SLOT(zeroControl (bool)));
  QObject::connect (&expConfigDialog, SIGNAL(setHeatingSpeed (int) ), &tController, SLOT(setHeatingSpeed (int)));

  SoundInformator soundInformator;
  connectInformator (&soundInformator, &pend, &tController, &experimen, &expConfigDialog);
  
  
  expConfigDialog.applaySettings ();  
  
  PendulumViewer pendViewer;
  pendViewer.assign (&pend);
  
  MainWindow mw;
  mw.assign (&experiment);
  QObject::connect (&mw, SIGNAL(configurePendulum ()), &expConfigDialog, SLOT(exec ()));
  
  QObject::connect (&mw, SIGNAL(showPendulumViewer ()), &pendViewer, SLOT(show ()));
  QObject::connect (&tController, SIGNAL(temperatureRead (double, double)),
      &mw, SLOT(temperatureReady(double, double)));
  QObject::connect (&tController, SIGNAL(powerRead (double)),
        &mw, SLOT(powerReady(double)));
      
  QObject::connect (&mw, SIGNAL(showOscillograph ()), &oscillograph, SLOT(show ()));
  
  mw.setPatternInfo (startDialog.getPattern ());
  mw.setPendulumInfo (startDialog.getPendulum ());
  
  
  mw.showMaximized ();
  */
  return app.exec ();
}
