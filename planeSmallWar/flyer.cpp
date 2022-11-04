#include "flyer.h"

Flyer::Flyer(QWidget *parent) :
    QWidget(parent),m_alive(false),m_picture(HERO1_PATH),
    m_rect(0,0,0,0),m_x(0),m_y(0),m_speed(0),m_initialed(false)
{
}

void Flyer::born()
{
    m_alive = true;
}

void Flyer::fly()
{
    m_y+=m_speed;
    m_rect.moveTo(m_x,m_y);
}

void Flyer::die()
{
    m_alive = false;
}
void Flyer::reborn()
{
    born();
}

void Flyer::setPos(int x, int y)
{
    m_x = x;
    m_y = y;

}

void Flyer::setX(int x)
{
    m_x = x;
}

void Flyer::setY(int y)
{
    m_y = y;
}

void Flyer::setSpeed(double speed)
{
    m_speed = speed;
}

void Flyer::reportError(const QString &str)
{
    QMessageBox::warning(this,"ERROR",str);
}

const QRect &Flyer::rect() const
{
    return m_rect;
}

void Flyer::setRect(const QRect &newRect)
{
    m_rect = newRect;
}

bool Flyer::initialed() const
{
    return m_initialed;
}

void Flyer::setInitialed(bool newInitialed)
{
    m_initialed = newInitialed;
}

unsigned int Flyer::speed() const
{
    return m_speed;
}

void Flyer::setRectSize()
{
    m_rect.setSize(picture().size()*BoxScaledRate);
}

void Flyer::moveRect()
{
    double offsetRate = (0.5-BoxScaledRate/2);
    m_rect.moveTo(m_x+picture().width()*offsetRate,m_y+picture().height()*offsetRate);
}

double Flyer::x() const
{
    return m_x;
}

double Flyer::y() const
{
    return m_y;
}

void Flyer::setPicture(const QString & picPath)
{
    m_picture.load(picPath);
}

void Flyer::setPicture(const QPixmap &other)
{
    m_picture = other;
}

bool Flyer::isAlive() const
{
    return m_alive;
}

QPixmap Flyer::picture() const
{
    return m_picture;
}

void Flyer::setAlive(bool alive)
{
    m_alive = alive;
}
