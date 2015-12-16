#ifndef EXPTEXTFILEWRITER_H_
#define EXPTEXTFILEWRITER_H_

#include <QObject>
#include <QIODevice>
#include "Pattern.h"
#include "Pendulum.h"
#include <QTime>

class ExpTextFileWriter: public QObject
{
  Q_OBJECT
public:
  ExpTextFileWriter (QIODevice* ioDevice);
  void writePatternInfo (const Pattern& pattern);
  void writePendulumInfo (const Pendulum& pendulum);
public slots:
  void dataReady (double G, double Q, double R, double T, double period);
private:
  QIODevice* ioDevice;
  QTime timer;
};

#endif /*EXPTEXTFILEWRITER_H_*/
