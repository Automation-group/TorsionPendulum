#ifndef RESCALIBRATEDIALOG_H_
#define RESCALIBRATEDIALOG_H_

#include <QDialog>
#include <QTimer>
#include "ui_resistorCalibrateForm.h"

class ResCalibrateDialog : public QDialog
{
  Q_OBJECT
public:
  ResCalibrateDialog ();
signals:
  void enableMagnet ();
  void disableMagnet ();
  void runPend ();
  void stopPend ();
  void setResistor (int code);
public slots:
  void periodDataReaded (int number, int maxAmpl, int minAmpl, int period);
private slots:
  void clear ();
private:
  Ui_ResistorCalibrateForm ui;
  QTimer timer;
  int counter;
  double zero;
};

#endif /*RESCALIBRATEDIALOG_H_*/
