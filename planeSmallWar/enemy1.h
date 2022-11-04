#ifndef ENEMY1_H
#define ENEMY1_H
#include<enemy.h>
#include<bulletred.h>
class Enemy1 : public Enemy
{
    Q_OBJECT
public:
    explicit Enemy1(QWidget *parent = nullptr);

    void loadBullet()override;
    void prepareMagazinesVector()override;

private:
    QVector<Bullet*> m_redMagazine;
signals:

};

#endif // ENEMY1_H
