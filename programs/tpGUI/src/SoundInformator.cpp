#include "SoundInformator.h"
#include "tpGlobal.h"
#include <QMutexLocker>
#include <QtDebug>
#include <QProcess>
#include <QStringList>

SoundInformator::SoundInformator ()
  :QThread (), terminated (false), maxTemp (600)
{
  start ();   
  //addToPlay (tr("/home/lexa/workspaces/Крут. маятник/tpGUI/sound/1.wav"));
  //addToPlay (tr("/home/lexa/workspaces/Крут. маятник/tpGUI/sound/1.wav"));
  //addToPlay (tr("/home/lexa/workspaces/Крут. маятник/tpGUI/sound/1.wav"));
  //addToPlay (tr("sound/7.wav"));
}

SoundInformator::~SoundInformator ()
{
  terminated = true;
  wait ();
}

void SoundInformator::beginMeasurement ()
{
  QMutexLocker locker(&playListMutex);
  repeatList.clear ();    
}
  
void SoundInformator::pendulumDisconnected ()
{
  addToRepeat (tr("sound/attention.wav"));
  addToRepeat (tr("sound/pendulumDisconnected.wav"));
}
  
void SoundInformator::zeroControlFailed ()
{
  addToPlay (tr("sound/attention.wav"));
  addToPlay (tr("sound/zeroControlFailed.wav"));
}
  
void SoundInformator::zeroWarning ()
{
  addToPlay (tr("sound/attention.wav"));
  addToPlay (tr("sound/zeroWarning.wav"));
}
  
void SoundInformator::bigAmplitude ()
{
  addToPlay (tr("sound/attention.wav"));
  addToPlay (tr("sound/bigAmplitude.wav"));
}
  
void SoundInformator::smallAmplitude ()
{
  addToPlay (tr("sound/attention.wav"));
  addToPlay (tr("sound/smallAmplitude.wav"));
}
  
void SoundInformator::deviationFailed ()
{
  addToRepeat (tr("sound/attention.wav"));
  addToRepeat (tr("sound/deviationFailed.wav"));
}
  
void SoundInformator::temperatureRead (double temperature, double speed)
{
  if (temperature > maxTemp)
      addToPlay (tr("sound/cooling.wav"));
}
  
void SoundInformator::dataReady (double G, double Q, double R, double T)
{
  
}

void SoundInformator::setMaxTemperature (int temp)
{
  maxTemp = temp;
}

void SoundInformator::metakonDisconnected ()
{
  addToRepeat (tr("sound/attention.wav"));
  addToRepeat (tr("sound/metakonDisconnected.wav"));  
}

void SoundInformator::run ()
{
  while (!terminated)
  {
    playListMutex.lock ();
    playListWaitCondition.wait (&playListMutex, 500);
    
    QString soundFile;
    
    if (!playList.isEmpty ())
    {
      soundFile = playList.first ();
      playList.pop_front ();
    }
    
    QStringList list (repeatList);
    playListMutex.unlock ();
    
    for (QStringList::const_iterator i = list.constBegin (); i != list.constEnd (); ++i)
    {
      play (*i);
    }
    
    if (!soundFile.isEmpty ())
    {
       play (soundFile);
    }    
  }
}

void SoundInformator::play (const QString& filename)
{
  QProcess process;
  QStringList args;
  args << filename;
  process.start ("kaboodle", args);
  process.waitForFinished (5000);
}

void SoundInformator::addToPlay (const QString& filename)
{
  QMutexLocker locker(&playListMutex);

  if (!playList.contains (filename))
  {
    playList.push_back (filename);
    playListWaitCondition.wakeOne ();
  }
}

void SoundInformator::addToRepeat (const QString& filename)
{
  QMutexLocker locker(&playListMutex);
  repeatList.push_back (filename);
  playListWaitCondition.wakeOne ();  
}
