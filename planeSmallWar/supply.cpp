#include "supply.h"

Supply::Supply(QWidget *parent)
    : Flyer{parent},m_angle(-45)
{
}

void Supply::born()
{
 setAlive(true);
 srand((unsigned)time(NULL));
 if(!picture())
 {
     reportError("无补给包图片");
 }
 int newx = rand()%static_cast<int>(GAME_WIDTH-picture().width());
 setX(newx);
 setY(0);
}

void Supply::fly()
{
    setX(x()+speed()*qCos(angle()*M_PI/180));
    setY(y()+speed()*qSin(angle()*M_PI/180));
    moveRect();
    if(x()<0||x()>GAME_WIDTH-picture().width())
    {
        setAngle(180 - angle());
    }
    if(y()<0||y()>GAME_HEIGHT-picture().height())
    {
        setAngle(-angle());
    }
}

double Supply::angle() const
{
    return m_angle;
}

void Supply::setAngle(double newAngle)
{
    m_angle = newAngle;
}
