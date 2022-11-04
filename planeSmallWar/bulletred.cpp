#include "bulletred.h"

BulletRed::BulletRed(QWidget *parent)
    : Bullet{parent}
{
    setAngle(-90);
    setPicture(BULLET2_PATH);
    ProcessPicture();
    setRectSize();
    moveRect();
    setDamage(Red_Damage);
    setSpeed(Red_Speed);
}

void BulletRed::born()
{
    setAlive(true);
}
