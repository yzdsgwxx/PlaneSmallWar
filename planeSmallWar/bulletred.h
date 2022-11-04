#pragma once
#include<Bullet.h>
class BulletRed :
      public Bullet
{
public:
    BulletRed(QWidget *parent = nullptr);
    void born() override;
};

