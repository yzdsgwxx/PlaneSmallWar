#include "boss.h"

Boss::Boss(QWidget *parent) : Plane(parent)
{
  m_alive=true;
  m_pic.load(":/images/boss.png");
  m_x=GAME_WIDTH/2-m_pic.width()/2;
  m_y=20;
  m_rect.setSize(QSize(m_pic.width(),m_pic.height()));
}
