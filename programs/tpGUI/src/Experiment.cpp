#include "Experiment.h"
#include "tpGlobal.h"
#include <math.h>

Experiment::Experiment (PController* pController, TController* tController)
  : pController (pController), tController (tController),
  currentTemperature (23.0), beginMstTemperature (23.0)  
{
  connect (pController, SIGNAL(endMeasurement (double, double, double)),
      this, SLOT(endMeasurement (double, double, double)));

  connect (pController, SIGNAL(paused (bool)),
      this, SLOT(pause (bool)));
  
  connect (tController, SIGNAL(temperatureRead (double, double)),
      this, SLOT(temperatureRead (double, double)));
}

void Experiment::setPendulum (const Pendulum& pendulum)
{
  Experiment::pendulum = pendulum;
}

void Experiment::setPattern (const Pattern& pattern)
{
  Experiment::pattern = pattern;
}

void Experiment::start ()
{
  tController -> startMeasurements ();  
  tController -> startHeating ();
  pController -> runMeasurements ();
}

void Experiment::stop ()
{
  tController -> stopMeasurements (); 
  tController -> stopHeating ();
  pController -> stopMeasurements ();
}

void Experiment::temperatureRead (double temperature, double speed)
{
  currentTemperature = temperature;
}

void Experiment::beginMeasurement ()
{
  beginMstTemperature = currentTemperature;
}

void Experiment::endMeasurement (double period, double decrement, double correlation)
{
  double J = pendulum.getJ ();
  double k0 = 4.0 * pow (PI, 2) * J / pow (period, 2.0) - pendulum.getKb ();
  double G = pattern.height () / ( pattern.alpha () * pattern.b () * pow (pattern.a (), 3.0)) * k0;
  decrement += pendulum.getKb () / k0 * (decrement - pendulum.getQp ()); 
  
  dataReady (G, decrement, correlation, currentTemperature, period);
  qDebug ("dataReady Lenght %3.3lf;a %3.3lf;b %3.3lf; alpha %3.3lf;period %3.3lf",
      pattern.height (), pattern.a (), pattern.b (), pattern.alpha (), period);
}

void Experiment::pause (bool enable)
{
  pController -> pause (enable);
  paused (enable);
}
