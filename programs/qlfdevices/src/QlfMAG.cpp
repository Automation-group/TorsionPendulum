#include "QlfMAG.h"
#include "QlfThread.h"
#include <QMutexLocker>

QlfMAG::QlfMAG(QIODevice* ioDevice) :
	ioDevice(ioDevice), mutex(), waitCondition(), terminated(false), tubThread(
			this, &QlfMAG::runThread), readLineFlag(false)
{
	timer.start();
	tubThread.start();
}

QlfMAG::~QlfMAG()
{
	terminated = true;
	tubThread.wait();
	tubThread.terminate();
}

void QlfMAG::run(int msTimeout)
{
	QByteArray buf("GC");
	buf.append(QByteArray::number(msTimeout));
	buf.append('\n');
	ioDevice -> write(buf);
}

void QlfMAG::stop()
{
	ioDevice -> write("SC\n", 3);
}

char QlfMAG::testConnection()
{
	ioDevice -> write("ID\n", 3);
	QByteArray buf = readLine();
	if ( buf=="IDf75579a00a4f096497b08ac2bfe40770\n" )
		return 1;
	return 0;
}

QByteArray QlfMAG::readLine()
{
	QMutexLocker locker(&mutex);
	if (buffer.isEmpty())
	{
		readLineFlag = true;
		if (!waitCondition.wait(&mutex) )
		{
			readLineFlag = false;
			return QByteArray();
		}
	}

	QByteArray buf = buffer.front();
	buffer.pop_front();
	readLineFlag = false;
	return buf;
}

void QlfMAG::resetTimer()
{
	timer.restart();
}

void QlfMAG::onCode(QByteArray& data)
{
	data.remove(0, 2);
	data.chop(1);

	dataReady(data.toInt(), timer.elapsed());
}

void QlfMAG::runThread(TUB_Thread* thread)
{
	while (!terminated)
	{
		if ( !ioDevice -> isOpen())
			continue;

		QByteArray buf = ioDevice -> readLine(100);

		if (buf.isEmpty() && !readLineFlag)
			continue;

		if (buf.startsWith("GD"))
		{
			onCode(buf);
			continue;
		}

		QMutexLocker locker(&mutex);

		buffer.push_back(buf);
		waitCondition.wakeOne();
	}
}
