#include "enemy.h"
#include<config.h>
#include<qdebug.h>
Enemy::Enemy(QWidget *parent)
    :Plane(parent)
{

}

void Enemy::fly()
{
    setY(y()+speed());
    moveRect();
    if(y()>GAME_HEIGHT)
    {
        die();
    }
}

void Enemy::born()
{
    if(!picture())reportError("未加载敌机图片");
    setAlive(true);
    double newX =rand()%static_cast<int>(GAME_WIDTH-picture().width());
    setX(newX);
    setY(-picture().height());
    setRectSize();
    moveRect();
    resetPreviousHp();
}
