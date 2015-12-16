#include "Temperature.h"

Temperature::Temperature (QlfRNet* rnet)
  : metakon (rnet)
{
  timer = new QTimer (this);
  connect (timer, SIGNAL(timeout()), this, SLOT(onTimer()));
}

void Temperature::onTimer ()
{
  
}
