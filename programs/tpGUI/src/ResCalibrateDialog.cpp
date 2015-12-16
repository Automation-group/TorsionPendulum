#include "ResCalibrateDialog.h"

ResCalibrateDialog::ResCalibrateDialog ()
  : QDialog (), counter (0), zero (0.0)
{
  ui.setupUi (this);
  
  timer.setSingleShot (true);
  timer.setInterval (2000);
  
  connect (ui.pbStart, SIGNAL(clicked()), this, SLOT (clear()));
  connect (ui.pbStart, SIGNAL(clicked()), this, SIGNAL (enableMagnet()));
  connect (ui.pbStart, SIGNAL(clicked()), &timer, SLOT (start()));
  
  connect (&timer, SIGNAL (timeout()), this, SIGNAL (disableMagnet ()));
  connect (&timer, SIGNAL (timeout()), this, SIGNAL (runPend ()));
  connect (ui.pbStop, SIGNAL(clicked()), this, SIGNAL (stopPend()));
  
  connect (ui.sbResistor, SIGNAL(valueChanged(int)), this, SIGNAL (setResistor(int)));
  //connect (ui.hsResistor, SIGNAL(valueChanged(int)), this, SIGNAL (setResistor(int)));
  
  //connect (ui.pbStart, SIGNAL(clicked()), this, SIGNAL (startADC()));
  //connect (ui.pbStop, SIGNAL(clicked()), this, SIGNAL (stopADC()));
}

void ResCalibrateDialog::clear ()
{
  counter = 0;
  zero = 0.0;
}

void ResCalibrateDialog::periodDataReaded (int number, int maxAmpl, int minAmpl, int period)
{
  if (number < 10) return;
  if (number > 80) return;
  if (maxAmpl > 500) return;
  if (minAmpl < -500) return;
  
  counter ++;
  zero += maxAmpl + minAmpl;
  ui.lcdNumber -> display (zero / counter);
}
