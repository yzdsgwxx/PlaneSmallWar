#ifndef ENEMY2_H
#define ENEMY2_H
#include<enemy.h>
#include<bulletred.h>
class Enemy2 : public Enemy
{
    Q_OBJECT
public:
    explicit Enemy2(QWidget *parent = nullptr);
    void loadBullet()override;
    void prepareMagazinesVector()override;

private:
    QVector<Bullet*> m_redMagazine;
signals:

};

#endif // ENEMY2_H
