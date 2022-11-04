#ifndef ENEMY_H
#define ENEMY_H
#include<QRect>
#include<QPixmap>
#include<Ebullet.h>
#include<qtimer.h>
#include<Plane.h>
class Enemy:public Plane
{
public:
    Enemy(QWidget *parent = nullptr);
    void fly()override;
    void born()override;

protected:

};

#endif // ENEMY_H
