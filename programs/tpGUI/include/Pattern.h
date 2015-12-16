#ifndef PATTERN_H_
#define PATTERN_H_

#include <QObject>
#include <QString>

class Pattern  //: public QObject
{
//  Q_OBJECT  
public:  
  /** Толщина
   */
  double& thickness () { return _thickness; }
  
  /** Ширина образца, м
   */
  double& width () { return _width; }
  
  /** Длина образца, м
   */
  double& height () { return _height; }

  /** Толщина
   */
  double thickness () const { return _thickness; }
  
  /** Ширина образца, м
   */
  double width () const { return _width; }
  
  /** Длина образца, м
   */
  double height () const { return _height; }
  
  double alpha () const;
  
  double a () const;
  double b () const;
  
private:
  double _thickness;
  double _width;
  double _height;
};

#endif /*PATTERN_H_*/
