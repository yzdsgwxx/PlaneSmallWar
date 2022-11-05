#include "bulletBlue.h"
BulletBlue::BulletBlue(QWidget *parent)
    :Bullet(parent)
{
    setAngle(Blue_Angle);
    setPicture(BULLET1_PATH);
    setUnScaledPicture(BULLET1_PATH);
    ProcessPicture();
    setRectSize();
    moveRect();
    setDamage(Blue_Damage);
    setSpeed(Blue_Speed);
}


