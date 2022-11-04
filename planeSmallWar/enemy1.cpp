#include "enemy1.h"

Enemy1::Enemy1(QWidget *parent)
    : Enemy{parent}
{
    QPixmap pixmap(ENEMY1_PATH);
    setPicture(pixmap.scaled(pixmap.size()*0.7));
    setTotalHp(Enemy1_Hp);
    setSpeed(Enemy1_Speed);
    prepareMagazinesVector();
    setShootingInterval(Enemy1_ShootingRate);
    setCollidingInjury(Enemy1_CollidingInjury);
    setInitialed(true);
}

void Enemy1::loadBullet()
{
    if(!isAlive())return;
        for(auto sIt = magazineVector()[0].begin();sIt !=magazineVector()[0].end();sIt++)
        {
            if(!(*sIt)->isAlive())
            {
                (*sIt)->setPos(x()+picture().width()/2-(*sIt)->picture().width()/2,rect().y()+rect().height());
                (*sIt)->reborn();
                return;
            }
        }
}

void Enemy1::prepareMagazinesVector()
{
    for(int i = 0;i<20;i++)
    {
        BulletRed *bullet = new BulletRed(this);
        m_redMagazine.push_back(bullet);
    }


    QVector<QVector<Bullet*>> newMagazineVector;
    newMagazineVector.push_back(m_redMagazine);

    setMagazineVector(newMagazineVector);
}
