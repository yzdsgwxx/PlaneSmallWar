#include<heroplane.h>
#include<bulletBlue.h>
#include<bullethuge.h>
HeroPlane::HeroPlane(QWidget * parent)
    :Plane(parent),m_killAll(0),m_hugeBulletAmount(1),m_invincible(false),
      m_quickShoot(false),m_strafe(false),m_annularShoot(false),m_strafeAngle(0),m_strafeOut(true)
{
    setSpeed(10);
    m_strafeTimer.setInterval(Strafe_Interval);
    connect(&m_strafeTimer,&QTimer::timeout,this,&HeroPlane::loadStrafeBullet);
    m_strafeTimer.start();
}

void HeroPlane::born()
{
    if(!picture())reportError("未加载英雄飞机图片");
    setAlive(true);
    setX(GAME_WIDTH/2-picture().width()/2);
    setY(GAME_HEIGHT-picture().height());
    setRectSize();
    moveRect();
    resetPreviousHp();
}

void HeroPlane::die()
{
    setAlive(false);
    emit heroDie();
}

void HeroPlane::shootBullet()
{
    //普通子弹
    for(auto it=magazineVector().begin();it!=magazineVector().end();it++)
    {
        for(auto sIt = (*it).begin();sIt !=(*it).end();sIt++)
        {
            if((*sIt)->isAlive())
            {
                (*sIt)->fly();
            }
        }
    }
    //特殊子弹
    for(auto it = hugeMagazine().begin();it!=hugeMagazine().end();it++)
    {
        if((*it)->isAlive())
        {
            (*it)->fly();
        }
    }
}

void HeroPlane::prepareHugeBullet()
{
    for(int i = 0;i<4;i++)
    {
        m_hugeMagazine.push_back(new BulletHuge(this));
    }
}

void HeroPlane::loadHugeBullet()
{
    qDebug()<<"HeroPlane::loadHugeBullet().hugeBulletAmount"<<hugeBulletAmount();
    if(hugeBulletAmount()<=0){return;}
    for(auto it = m_hugeMagazine.begin();it!=m_hugeMagazine.end();it++)
    {
        if(!(*it)->isAlive())
        {
            (*it)->reborn();
            (*it)->setPos(x(),y()-(*it)->picture().height());
            break;
        }
    }
    for(auto it = m_hugeMagazine.begin();it!=m_hugeMagazine.end();it++)
    {
        if(!(*it)->isAlive())
        {
            (*it)->reborn();
            (*it)->setPos(x()+picture().width()-(*it)->picture().width(),y()-(*it)->picture().height());
            break;
        }
    }
    qDebug()<<"HeroPlane::loadHugeBullet().hugeBulletAmount"<<m_hugeMagazine.size();
    setHugeBulletAmount(hugeBulletAmount()-1);
}

void HeroPlane::loadBullet()
{
    if(!isAlive())return;
    int index =(int)BulletIndex::normal;
    for(auto it = magazineVector()[index].begin();it!=magazineVector()[index].end();it++)
    {
        if(!(*it)->isAlive())
        {
            (*it)->reborn();
            (*it)->setPos(x()+picture().width()/2-(*it)->picture().width()/2,y()-(*it)->picture().height());
            break;
        }
    }
}

void HeroPlane::loadStrafeBullet()
{
    int index = (int)BulletIndex::strafe;
    if(isStrafe())
    {
        for(auto it = magazineVector()[index].begin();it!=magazineVector()[index].end();it++)
        {
            if(!(*it)->isAlive())
            {
                (*it)->setAngle(90+strafeAngle());
                (*it)->ProcessPicture();
                (*it)->reborn();
                (*it)->setPos(x(),y()-(*it)->picture().height());
                break;
            }
        }
        for(auto it = magazineVector()[index].begin();it!=magazineVector()[index].end();it++)
        {
            if(!(*it)->isAlive())
            {
                (*it)->setAngle(90-strafeAngle());
                (*it)->ProcessPicture();
                (*it)->reborn();
                (*it)->setPos(x()+picture().width()-(*it)->picture().width(),y()-(*it)->picture().height());
                break;
            }
        }
        if(isStrafeOut())
        {
            setStrafeAngle(strafeAngle()+4);
            if(strafeAngle()>=15)
            {
                setStrafeOut(false);
            }
        }
        else
        {
            setStrafeAngle(strafeAngle()-4);
            if(strafeAngle()<=0)
            {
                setStrafeOut(true);
            }
        }
    }
}
void HeroPlane::prepareMagazinesVector()
{
    prepareHugeBullet();
    for(int i = 0;i<20;i++)
    {
        m_blueMagazine.push_back(new BulletBlue(this));
        m_strafeMagazine.push_back(new BulletBlue(this));
    }


    QVector<QVector<Bullet*>> newMagazineVector;
    newMagazineVector.push_back(m_blueMagazine);
    newMagazineVector.push_back(m_strafeMagazine);

    setMagazineVector(newMagazineVector);
}

void HeroPlane::OnKillAll()
{
}

void HeroPlane::OnInvincible()
{
    if(isInvincible()){return;}
    setInvincible(true);
    QTimer::singleShot(Invincible_Lastingmsc,this,[=](){OffInvincible();});
}

void HeroPlane::OnQuickShoot()
{
    //技能时间内又吃到相同技能，只按第一个技能持续时间算。
    if(isQuickShoot()){return;}
    setQuickShoot(true);
    setShootingInterval(initShootingInterval()/1.5);
    QTimer::singleShot(QuickShoot_Lastingmsc,this,[=](){OffQuickShoot();});
}

void HeroPlane::OnStrafe()
{
    if(isStrafe()){return;}
    setStrafe(true);
    setStrafeAngle(0);
    QTimer::singleShot(Strafe_Lastingmsc,this,[=](){OffStrafe();});
}

void HeroPlane::OnAnnularShoot()
{

}

void HeroPlane::OffInvincible()
{
    setInvincible(false);
}

void HeroPlane::OffQuickShoot()
{
    setQuickShoot(false);
    resetShootTimer();
}

void HeroPlane::OffStrafe()
{
    setStrafe(false);
    setStrafeAngle(0);
}

void HeroPlane::OffAnnularShoot()
{

}

bool HeroPlane::isInvincible() const
{
    return m_invincible;
}

bool HeroPlane::isQuickShoot() const
{
    return m_quickShoot;
}


bool HeroPlane::isStrafe() const
{
    return m_strafe;
}

bool HeroPlane::isAnnularShoot() const
{
    return m_annularShoot;
}

void HeroPlane::setQuickShoot(bool newQuickShoot)
{
    m_quickShoot = newQuickShoot;
}

void HeroPlane::setAnnularShoot(bool newAnnularShoot)
{
    m_annularShoot = newAnnularShoot;
}

void HeroPlane::setStrafe(bool newStrafe)
{
    m_strafe = newStrafe;
}

void HeroPlane::setInvincible(bool newInvincible)
{
    m_invincible = newInvincible;
    qDebug()<<"HeroPlane::setInvincible"<<isInvincible();
}

int HeroPlane::killAllAmount() const
{
    return m_killAll;
}

void HeroPlane::setKillAll(int newKillAll)
{
    m_killAll = newKillAll;
}

int HeroPlane::hugeBulletAmount() const
{
    return m_hugeBulletAmount;
}

void HeroPlane::setHugeBulletAmount(int newHugeBulletAmount)
{
    m_hugeBulletAmount = newHugeBulletAmount;
}

double HeroPlane::strafeAngle() const
{
    return m_strafeAngle;
}

void HeroPlane::setStrafeAngle(double newStrafeAngle)
{
    m_strafeAngle = newStrafeAngle;
}

const QTimer &HeroPlane::getStrafeTimer() const
{
    return m_strafeTimer;
}

void HeroPlane::setStrafeTimer(double interval)
{
    m_strafeTimer.setInterval(interval);
}

bool HeroPlane::isStrafeOut() const
{
    return m_strafeOut;
}

void HeroPlane::setStrafeOut(bool newStrafeOut)
{
    m_strafeOut = newStrafeOut;
}

const QVector<Bullet *> &HeroPlane::hugeMagazine() const
{
    return m_hugeMagazine;
}


