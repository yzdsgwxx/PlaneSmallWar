#include "bulletred.h"

BulletRed::BulletRed(QWidget *parent)
    : Bullet{parent}
{
    setAngle(Red_Angle);
    setPicture(BULLET2_PATH);
    ProcessPicture();
    setRectSize();
    moveRect();
    setDamage(Red_Damage);
    setSpeed(Red_Speed);
}
