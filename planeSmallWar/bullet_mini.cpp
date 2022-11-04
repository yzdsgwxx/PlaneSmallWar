#include "bullet_mini.h"

Bullet_mini::Bullet_mini(QWidget *parent)
{
    this->m_speed = -BULLET_SPEED;
    damage = 1;
    //缩放子弹
    this->m_pic.load(":/images/bullet2.png");
    this->m_pic=this->m_pic.scaled(20,50);    this->m_alive= false;
    this->m_rect.setWidth(m_pic.width());
    this->m_rect.setHeight(m_pic.height());
    //初始化的时候也初始话图片坐标和框体坐标，防止乱跑
    this->m_rect.moveTo(-100, -100);
    this->m_x = -100;
    this->m_y = -100;
}
