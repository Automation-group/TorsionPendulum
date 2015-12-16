#ifndef QLFMAG_H_
#define QLFMAG_H_

#include <QObject>
#include <QIODevice> 
#include "QlfThread.h"
#include <QList>
#include <QMutex>
#include <QWaitCondition>
#include <QTime>

class QlfMAG: public QObject
{
	Q_OBJECT
public:
	
	QlfMAG (QIODevice* ioDevice);

	~QlfMAG ();
	
	/**
	 * Проверка соединения
	 * \return '0' - устройство не опознано;
	 * '1' - устройство опознано;
	 */
	char testConnection ();
	
	/**
	 * Провести измерение
	 * \return код АЦП
	 */
	int measure ();

public Q_SLOTS:

	void resetTimer ();

	/**
	 * Запустить измерения в непрерывном режиме
	 * \param msTimeout интервал измерений, мс
	 */
void run(int msTimeout = 100);

/**
 * Остановить измерения
 */
void stop();

Q_SIGNALS:
/**
 * Результат измерения в непрерывном режиме
 * \param code код АЦП
 * \param msTime время прихода данных в мс
 */
void dataReady (int code, int msTime);

private:
  typedef QlfThread<QlfMAG> TUB_Thread;
  void runThread(TUB_Thread* thread);

  void onCode(QByteArray& data);
  QByteArray readLine();

private:
  QIODevice* ioDevice;
  QList<QByteArray> buffer;
  TUB_Thread tubThread;
  QMutex mutex;
  QWaitCondition waitCondition;
  bool terminated;
  bool readLineFlag;
  QTime timer;
};

#endif /*QLFMAG_H_*/
