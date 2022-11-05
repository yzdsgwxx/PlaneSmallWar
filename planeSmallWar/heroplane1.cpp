#include "heroplane1.h"
HeroPlane1::HeroPlane1(QWidget *parent)
    : HeroPlane(parent)
{

    setPicture(HERO1_PATH);
    setPicture(picture().scaled(picture().size()*0.8));
    prepareMagazinesVector();
    born();
    setTotalHp(Hero1_Hp);
    setShootingInterval(Shooting_Interval);
    setCollidingInjury(Hero1_CollidingInjury);
    setInitialed(true);
}



