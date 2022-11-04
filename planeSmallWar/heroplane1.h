#ifndef HEROPLANE1_H
#define HEROPLANE1_H

#include <QWidget>
#include<heroplane.h>
#include<bulletBlue.h>
class HeroPlane1 : public HeroPlane
{
    Q_OBJECT
public:
    explicit HeroPlane1(QWidget *parent = nullptr);
    void loadBullet()override;
    void prepareMagazinesVector()override;
private:
   QVector<Bullet*>m_blueMagazine;
signals:

};

#endif // HEROPLANE1_H
