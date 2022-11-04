#include<heroplane.h>
#include<QMessageBox>
HeroPlane::HeroPlane(QWidget * parent)
    :Plane(parent),m_killAll(false),m_invincible(false),m_quickShoot(false),m_strafe(false),m_annularShoot(false)
{
    setSpeed(10);
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

void HeroPlane::OnKillAll()
{
    setKillAll(true);
}

void HeroPlane::OnInvincible()
{
    setInvincible(true);
}

void HeroPlane::OnQuickShoot()
{
    //技能时间内又吃到相同技能，只按第一个技能持续时间算。
    if(quickShoot()){return;}
    setQuickShoot(true);
    setShootingInterval(initShootingInterval()/1.5);
    QTimer::singleShot(QuickShoot_Lastingmsc,this,[=](){OffQuickShoot();});
}

void HeroPlane::OnStrafe()
{

}

void HeroPlane::OnAnnularShoot()
{

}

void HeroPlane::OffInvincible()
{

}

void HeroPlane::OffQuickShoot()
{
    setQuickShoot(false);
    resetShootTimer();
}

void HeroPlane::OffStrafe()
{

}

void HeroPlane::OffAnnularShoot()
{

}

bool HeroPlane::killAll()
{
    return m_killAll;
}

bool HeroPlane::invincible()
{
    return m_invincible;
}

bool HeroPlane::quickShoot() const
{
    return m_quickShoot;
}


bool HeroPlane::strafe() const
{
    return m_strafe;
}

bool HeroPlane::annularShoot() const
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

void HeroPlane::setKillAll(bool newKillAll)
{
    m_killAll = newKillAll;
}

void HeroPlane::setInvincible(bool newInvincible)
{
    m_invincible = newInvincible;
}


