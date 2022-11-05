#include "Plane.h"
Plane::Plane(QWidget *parent) :
    Flyer(parent),m_previousHp(10),m_totalHp(10)
{
}

double Plane::previousHp() const
{
    return m_previousHp;
}

void Plane::setPreviousHp(double newHp)
{
    m_previousHp = newHp;
}

const QTimer &Plane::shootTimer() const
{
    return m_shootTimer;
}

void Plane::setShootingInterval(int interval)
{
   m_shootTimer.setInterval(interval);
   if(!initialed())
   {
       startShootingTimer();
       setInitShootingInterval(interval);
   }
}

void Plane::startShootingTimer()
{
    if(!m_shootTimer.interval())reportError("未初始化发射计时器");
    QTimer::singleShot(rand()%1000,this,[=](){m_shootTimer.start();});
    connect(&m_shootTimer,&QTimer::timeout,this,&Plane::loadBullet);
}

void Plane::shootBullet()
{
    //普通子弹
    for(auto it=m_magazineVector.begin();it!=m_magazineVector.end();it++)
    {
        for(auto sIt = (*it).begin();sIt !=(*it).end();sIt++)
        {
            if((*sIt)->isAlive())
            {
                (*sIt)->fly();
            }
        }
    }
}

const QVector<QVector<Bullet *> > &Plane::magazineVector() const
{
    return m_magazineVector;
}

void Plane::setMagazineVector(const QVector<QVector<Bullet *> > &newMagazineVector)
{
    m_magazineVector = newMagazineVector;
}

double Plane::totalHp() const
{
    return m_totalHp;
}

void Plane::setTotalHp(double newTotalHp)
{
    m_totalHp = newTotalHp;
    m_previousHp = m_totalHp;
}

void Plane::resetPreviousHp()
{
    m_previousHp = m_totalHp;
}

double Plane::collidingInjury() const
{
    return m_collidingInjury;
}

void Plane::setCollidingInjury(double newCollidingInjury)
{
    m_collidingInjury = newCollidingInjury;
}

double Plane::initShootingInterval() const
{
    return m_initShootingInterval;
}

void Plane::setInitShootingInterval(double newInitShootingInterval)
{
    m_initShootingInterval = newInitShootingInterval;
}

void Plane::resetShootTimer()
{
    m_shootTimer.setInterval(m_initShootingInterval);
}
