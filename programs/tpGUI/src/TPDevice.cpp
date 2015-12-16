#include "TPDevice.h"
#include <QMutexLocker>
#include <QTextStream>
#include <QBuffer>
#include <QtGlobal>
#include <QtDebug>


TPDevice::TPDevice (TPSimulator* simulator)
  : simulator (simulator)
{
  //readOutBuffer.open (QIODevice::ReadWrite | QIODevice::Unbuffered);
  connect (simulator, SIGNAL (periodIsReady(int,int,int,int)),
      this, SLOT (periodIsReady(int,int,int,int)));
      //Qt::DirectConnection);
  
  connect (simulator, SIGNAL (adcIsReady(int)),
      this, SLOT (adcIsReady(int)));
      //Qt::DirectConnection);
}

qint64 TPDevice::readData (char* data, qint64 maxSize)
{
  if (readOutBuffer.isEmpty ())
  {
    QMutexLocker locker (&outMutex);
    if (outBuffer.isEmpty()) outWait.wait(&outMutex, 500);
    if (!outBuffer.isEmpty())
    {
      readOutBuffer = outBuffer.dequeue ();
    }    
  }
  
  qint64 result = qMin (maxSize, (qint64)readOutBuffer.size ());
  for (qint64 i = 0; i < result; i++)
    data[i] = readOutBuffer.data ()[i];
  readOutBuffer.remove (0, result);
  return result;
}

qint64 TPDevice::writeData (const char* data, qint64 maxSize)
{
  for (qint64 i = 0; i < maxSize; ++i)
    writeChar (data[i]);
  return maxSize;
}

void TPDevice::writeChar (char data)
{
  if (data == '\n')
  {
    analyseCommand (inBuffer);
    inBuffer.clear ();
  }
  else
    inBuffer.push_back (data);
}

void TPDevice::AddResonse (const QByteArray& response)
{
  QMutexLocker locker (&outMutex);
  outBuffer.enqueue (response);
  outWait.wakeOne ();  
}

void TPDevice::periodIsReady (int number, int maxAmpl, int minAmpl, int period)
{
  QByteArray buf;
  QBuffer buffer (&buf);
  buffer.open (QIODevice::WriteOnly);
  QTextStream str (&buffer);
  str << "PR" << number << "," << maxAmpl << ",";
  str << minAmpl << ", " << period << '\n';
  buffer.close ();
  AddResonse (buf);
}

void TPDevice::adcIsReady (int code)
{
  QByteArray buf;
  QBuffer buffer (&buf);
  buffer.open (QIODevice::WriteOnly);
  QTextStream str (&buffer);
  str << "AR" << code << '\n';
  buffer.close ();
  AddResonse (buf);
}

void TPDevice::analyseCommand (const QString& command)
{
  qDebug () << "TDDevice recive command" << command;
  
  if (command == "EM")
  {
    simulator -> enableMagnet ();
    return;
  }
  
  if (command == "DM")
  {
    simulator -> disableMagnet ();
    return;
  }
  
  if (command == "RP")
  {
    simulator -> runMeasurements ();
    return;
  }
  
  if (command == "PP")
  {
    simulator -> runPreviewMode ();
  }
  
  if (command == "SP")
    simulator -> stop ();
  
  if (command == "RA")
    simulator -> runADC ();
  
  if (command == "SA")
    simulator -> stopADC ();
  
  if (command == "GS")
    AddResonse ("GS?\n");
}
