#ifndef BULLET_H
#define BULLET_H
#include<flyer.h>
#include<QtMath>
#include<cmath>
class Bullet :public Flyer
{

public:
    Bullet(QWidget *parent = nullptr);

public:
    void fly()override;
    virtual void ProcessPicture();
    void setAngle(double angle);
    void setDamage(double damage);
    double angle() const;
    double damage() const;


private:
    double m_angle;
    double m_damage;
};

#endif // BULLET_H
