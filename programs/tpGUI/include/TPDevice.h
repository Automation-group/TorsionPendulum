#ifndef TPDEVICE_H_
#define TPDEVICE_H_

#include <QObject>
#include <QIODevice>
#include <QByteArray>
#include <QWaitCondition>
#include <QMutex>
#include <QString>
#include <QQueue>
#include <QBuffer>

#include "TPSimulator.h"

class TPDevice: public QIODevice
{
  Q_OBJECT
public:
  TPDevice (TPSimulator* simulator);
protected:
  qint64 readData (char* data, qint64 maxSize);
  qint64 writeData (const char* data, qint64 maxSize);
private:
  void writeChar (char data);
  void analyseCommand (const QString& command);
  void AddResonse (const QByteArray& response);
private slots:
  void periodIsReady (int number, int maxAmpl, int minAmpl, int period);
  void adcIsReady (int code);
private:
  QQueue<QByteArray> outBuffer;
  QByteArray readOutBuffer;
  QByteArray inBuffer;
  
  TPSimulator* simulator;
  //QMutex inMutex;
  mutable QMutex outMutex;
  mutable QWaitCondition outWait;
};

#endif /*TPDEVICE_H_*/
