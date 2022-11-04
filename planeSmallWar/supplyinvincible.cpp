#include "supplyinvincible.h"

SupplyInvincible::SupplyInvincible(QWidget *parent)
    : Supply{parent}
{
    setPicture(":/images/supply-invincible.png");
    setSpeed(Invincible_Speed);
    setRectSize();
    moveRect();
}
