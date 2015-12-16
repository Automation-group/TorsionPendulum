#include "TextInformant.h"
#include "tpGlobal.h"
#include <QtDebug>
#include <QVBoxLayout>
#include <QTime>

TextInformant::TextInformant ()
  :QDialog (), maxTemp (600)
{
  setWindowFlags (Qt::Popup | Qt::Dialog);
  messages = new QTextEdit;// (this);
  messages -> setReadOnly (true);
  QFont font;
  font.setWeight (30);
  messages -> setCurrentFont (font);
  
  QVBoxLayout *mainLayout = new QVBoxLayout;
  mainLayout -> addWidget (messages);
  setLayout (mainLayout);
  
  resize (QSize (500, 400));
}

void TextInformant::beginMeasurement ()
{
}
  
void TextInformant::pendulumDisconnected ()
{
  addMessage (tr("Потеряна связь с маятником!"));
}
  
void TextInformant::zeroControlFailed ()
{
  addMessage (tr("Не могу отрегулировать ноль!"));
}
  
void TextInformant::zeroWarning ()
{
  addMessage (tr("Ноль ушел из допустимых пределов!"));
}
  
void TextInformant::bigAmplitude ()
{
  addMessage (tr("Амплитуда колебаний больше допустимой!"));
}
  
void TextInformant::smallAmplitude ()
{
  addMessage (tr("Амплитуда колебаний меньше допустимой!"));
}
  
void TextInformant::deviationFailed ()
{
  addMessage (tr("Не могу отклонить маятник!"));
}
  
void TextInformant::temperatureRead (double temperature, double speed)
{
  static bool flag = true;
  if (flag && temperature > maxTemp)
  {
    addMessage (tr("Пора охлаждать термокамеру!"));
    flag = false;
  }
}
  
void TextInformant::dataReady (double G, double Q, double R, double T, double period)
{
  
}

void TextInformant::setMaxTemperature (int temp)
{
  maxTemp = temp;
}

void TextInformant::metakonDisconnected ()
{
  addMessage (tr("Потеряна связь с 'Метаконом'!"));
}

void TextInformant::addMessage (const QString& text)
{
  QString time = QTime::currentTime ().toString ("h:mm");
  QString buffer;
  buffer = "<h2><div><b>";
  buffer += tr("Время ") + time;
  buffer += ".</b> <FONT color=#FF0000>";
  buffer += text;
  buffer += "</FONT></div></h2><br/>";
  messages -> append (buffer);
  //messages -> scrollToAnchor (time);
  show ();
}
