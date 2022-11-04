#include "enemy2.h"

Enemy2::Enemy2(QWidget *parent)
    : Enemy{parent}
{
    QPixmap pixmap(ENEMY2_PATH);
    setPicture(pixmap.scaled(pixmap.size()*0.8));
    setTotalHp(Enemy2_Hp);
    setSpeed(Enemy2_Speed);
    prepareMagazinesVector();
    setShootingInterval(Enemy2_ShootingRate);
    setCollidingInjury(Enemy2_CollidingInjury);
    setInitialed(true);
}


void Enemy2::loadBullet()
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

void Enemy2::prepareMagazinesVector()
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
