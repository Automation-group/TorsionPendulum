#include "Pendulum.h"
#include <math.h> 

double Pendulum::getJ () const
{
  return getM1 () * pow (getR1 (), 2) + getM2 () * pow (getR2 (), 2) + getJp ();
}
