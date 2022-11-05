#include "Bullet.h"
#include<QtMath>
#include<QPixmap>
Bullet::Bullet(QWidget *parent)
    :Flyer(parent)
{
}

void Bullet::fly()
{
    setX(x()+speed()*qCos(angle()*M_PI/180));
    setY(y()-speed()*qSin(angle()*M_PI/180));
    moveRect();
    if(x()>GAME_WIDTH||x()<-picture().width()||y()>GAME_HEIGHT||y()<-picture().height())
    {
        die();
    }
}

void Bullet::ProcessPicture()
{
    if(!picture())
        reportError("未加载子弹图片");
    if(!angle())
        reportError("未初始化子弹角度");
    QTransform transform;
    transform.scale(1,1);
    transform.rotate(360-angle());
    setPicture(unScaledPicture().transformed(transform));

}

double Bullet::angle() const
{
    return m_angle;
}

double Bullet::damage() const
{
    return m_damage;
}

//void Bullet::setDamage(Bullet::Damage damage)
//{
//    m_damage = damage;
//}

void Bullet::setAngle(double angle)
{
    m_angle =angle;
}

void Bullet::setDamage(double damage)
{
    m_damage = damage;
}
