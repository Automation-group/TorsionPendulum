#include <math.h>
#include <QtGlobal>
#include "Pattern.h"
#include "tpGlobal.h"
#include <QtDebug>

double Pattern::a () const
{
  return qMin (_width , _thickness );
}

double Pattern::b () const
{
  return qMax (_width , _thickness );
}

double Pattern::alpha () const
{
  double result = 0.0;
  for (int i = 0; i < 3; ++i)
  { 
    double k = 1 + i * 2;
    double r = 1.0 / pow (k, 5.0) * tanh ( PI * k * b () / (2.0 * a ()) ); 
    //qDebug() << "k" << k <<  " r" << r;
    result += r;
    //qDebug() << "res" << result;
  }  
  
  //qDebug() << "!" << 192.0 / pow (PI, 5.0) / (b () / a ();
  double alfa = (1.0 - 192.0 * a ()* result / pow (PI, 5.0) / b ()) / 3.0;
  //qDebug() << "alfa" << alfa << a()*1000.0 << b()*1000.0;
  return alfa;
}
