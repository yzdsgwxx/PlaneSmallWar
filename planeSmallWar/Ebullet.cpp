#include "Ebullet.h"

Ebullet::Ebullet()
{
    damage = 1;
    this->m_speed = BULLET_SPEED;
    this->m_pic.load(EBULLET_PATH1);
    this->m_alive = true;
    this->m_rect.setWidth(m_pic.width());
    this->m_rect.setHeight(m_pic.height());
    //初始化的时候也初始话图片坐标和框体坐标，防止乱跑
    this->m_rect.moveTo(-100, -100);
    this->m_x = -100;
    this->m_y = -100;
}

void Ebullet::updatePosition()
{
    if (!m_alive)
    {
        //移动位置
        m_y += m_speed;

        //移动框体
        m_rect.moveTo(m_x, m_y);

        //判断死亡
        if (m_y >=GAME_HEIGHT)
        {
            this->m_alive = true;
        }
    }


}
