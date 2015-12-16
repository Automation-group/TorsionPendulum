#include "ExpTextFileWriter.h"
#include <QTextStream>

ExpTextFileWriter::ExpTextFileWriter (QIODevice* ioDevice)
  : ioDevice (ioDevice)
{
  timer.start ();
}

void ExpTextFileWriter::writePatternInfo (const Pattern& pattern)
{
  
}

void ExpTextFileWriter::writePendulumInfo (const Pendulum& pendulum)
{
  
}

void ExpTextFileWriter::dataReady (double G, double Q, double R, double T, double period)
{
  QTextStream str (ioDevice);
  str << timer.elapsed () / 1000.0 << " " << fixed << 
  qSetRealNumberPrecision (3) << G / 1e9 << scientific
  << " " << Q << " " << T << " " << R << " " << period << endl;
}
