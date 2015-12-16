#ifndef PENDULUM_H_
#define PENDULUM_H_

class Pendulum
{
public:
  /** Конструктор */
  Pendulum ()
    :m1 (0.0), m2 (0.0), r1 (0.0), r2 (0.0),
    jp (0.0), kb (0.0), qp (0.0)
    { }  
  
  /**
   * Получить масса 1-го грузика
   * \return масса 1-го грузика в кг.
   */
  double getM1 () const {return m1; }
  
  /**
   * Задать массу 1-го грузика
   * \param newM масса 1-го грузика в кг.
   */
  void setM1 (double newM) { m1 = newM; }

  /**
   * Получить масса 2-го грузика
   * \return масса 2-го грузика в кг.
   */
  double getM2 () const {return m2; }

  /**
   * Задать массу 2-го грузика
   * \param newM масса 2-го грузика в кг.
   */  
  void setM2 (double newM) {m2 = newM; }
  
  /**
   * Получить расстояние до 1-го грузика
   * \return расстояние до 1-го грузика в м.
   */
  double getR1 () const {return r1; }
  
  /**
   * Задать расстояние до 1-го грузика
   * \param newM расстояние до 1-го грузика в м.
   */
  void setR1 (double newR) { r1 = newR; }

  /**
   * Получить расстояние до 2-го грузика
   * \return расстояние до 2-го грузика в м.
   */
  double getR2 () const {return r2; }

  /**
   * Задать массу 2-го грузика
   * \param newM расстояние до 2-го грузика в м.
   */  
  void setR2 (double newR) {r2 = newR; }  
  
  /**
   * Прочитать момент инерции маятника без грузов
   * \return момент инерции кг*м^2
   */
  double getJp () const {return jp; }
  
  /**
   * Задать момент инерции маятника без грузов
   * \param newJ момент инерции кг*м^2
   */  
  void setJp (double newJ) {jp = newJ; }
  
  /**
   * Получить жесткость подвеса
   * \return жесткость подвеса
   */
  double getKb () const {return kb; }

  /**
   * Задать жесткость подвеса
   * \param newK жесткость подвеса
   */
  void setKb (double newK) {kb = newK; }
  
  /**
   * Получить затухание подвеса
   * \return затухание
   */
  double getQp () const {return qp; }
  
  /**
   * Зазать затухания подвеса
   * \param newQp затухание
   */
  void setQp (double newQp) {qp = newQp; }
  
  /**
   * Получить момент инерции маятника
   */
  double getJ () const;
private:
  double m1;
  double m2;
  double r1;
  double r2;
  double jp;
  double kb;
  double qp;
};

#endif /*PENDULUM_H_*/
