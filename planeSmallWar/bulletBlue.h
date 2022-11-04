#pragma once
#include "Bullet.h"
class BulletBlue :
    public Bullet
{
public:
    BulletBlue(QWidget *parent = nullptr);
    void born() override;
};

