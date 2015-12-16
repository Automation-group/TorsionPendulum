#ifndef STARTERDIALOG_H_
#define STARTERDIALOG_H_

#include <QObject>
#include <QDialog>
#include <QlfRNet.h>
#include <QlfTornPend.h>
#include <qextserialport.h>
//
/*
#include "mainwindow.h"
#include "PendulumViewer.h"
#include "Experiment.h"
#include "ExpConfigDialog.h"
#include "ResCalibrateDialog.h"
#include "CalibrateFurnace.h"
#include "tpOscillograph.h"
#include "TPSimulator.h"
#include "TPDevice.h"
#include "ExpTextFileWriter.h"
#include "SoundInformator.h"
*/

#include "PController.h"
#include "TController.h"

#include "ui_starterDialog.h"


class StarterDialog: public QDialog
{
  Q_OBJECT
public:
  StarterDialog ();
  ~StarterDialog ();
private slots:
  void startExperiment ();
  void configure ();
  void calibrateFurnace ();
private:
  void createSerialPorts ();
  bool openSerialPorts ();
  void closeSerialPorts ();
  void showSerialPortErrors ();
  void createInformants ();
  void connectInformant (QObject* informant);
  void createControllers ();
  void setDefaultPID ();
private:
  QlfTornPend* tornPend;
  QlfRNet* rNet;
  QextSerialPort *rnetSPort;
  QextSerialPort *tpSPort;
  PController* pController;
  TController* tController;
  Ui_starterDialog ui;
};

#endif /*STARTERDIALOG_H_*/
