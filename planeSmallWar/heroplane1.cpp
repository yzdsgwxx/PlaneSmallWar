#include "heroplane1.h"

HeroPlane1::HeroPlane1(QWidget *parent)
    : HeroPlane(parent)
{

    setPicture(HERO1_PATH);
    setPicture(picture().scaled(picture().size()*0.8));
    prepareMagazinesVector();
    born();
    setTotalHp(Hero1_Hp);
    setShootingInterval(Hero1_ShootingRate);
    setCollidingInjury(Hero1_CollidingInjury);
    setInitialed(true);
}

void HeroPlane1::loadBullet()
{
    if(!isAlive())return;
    for(auto it=magazineVector().begin();it!=magazineVector().end();it++)
    {
        for(auto sIt = (*it).begin();sIt !=(*it).end();sIt++)
        {
            if(!(*sIt)->isAlive())
            {
                (*sIt)->reborn();
                (*sIt)->setPos(x()+picture().width()/2-(*sIt)->picture().width()/2,y()-(*sIt)->picture().height());
                break;
            }
        }
    }
}

void HeroPlane1::prepareMagazinesVector()
{
    for(int i = 0;i<20;i++)
    {
        m_blueMagazine.push_back(new BulletBlue(this));
    }
    QVector<QVector<Bullet*>> newMagazineVector;
    newMagazineVector.push_back(m_blueMagazine);
    setMagazineVector(newMagazineVector);
}



