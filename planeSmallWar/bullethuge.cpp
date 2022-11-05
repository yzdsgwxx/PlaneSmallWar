#include "bullethuge.h"

BulletHuge::BulletHuge(QWidget *parent)
    : Bullet{parent}
{
    setAngle(Huge_Angle);
    setPicture(BULLET0_PATH);
    ProcessPicture();
    setRectSize();
    moveRect();
    setDamage(Huge_Damage);
    setSpeed(Huge_Speed);
}

void BulletHuge::ProcessPicture()
{
    if(!picture())
        reportError("未加载子弹图片");
    QTransform transform;
    transform.rotate(360-angle());
    transform.scale(0.5,0.5);
    setPicture(picture().transformed(transform));
}
