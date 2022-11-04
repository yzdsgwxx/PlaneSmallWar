#ifndef PLANE_H
#define PLANE_H
#include<flyer.h>
#include<Bullet.h>
#include<QTimer>
class Plane : public Flyer
{
    Q_OBJECT
public:
    explicit Plane(QWidget *parent = nullptr);
    virtual void loadBullet()=0;
    virtual void prepareMagazinesVector()=0;
    void die()override;
    void shootBullet();
    void startShootingTimer();
    void resetShootTimer();

    double previousHp() const;
    double totalHp() const;
    const QTimer& shootTimer() const;
    const QVector<QVector<Bullet *> > &magazineVector() const;

    void setMagazineVector(const QVector<QVector<Bullet *> > &newMagazineVector);
    void setPreviousHp(double newHp);
    void setShootingInterval(int interval);
    void setTotalHp(double newTotalHp);

    void resetPreviousHp();
    double collidingInjury() const;
    void setCollidingInjury(double newCollidingInjury);
    double initShootingInterval() const;
    void setInitShootingInterval(double newInitShootingInterval);

private:
    double m_previousHp;
    double m_totalHp;
    double m_initShootingInterval;
    double m_collidingInjury;
    QTimer m_shootTimer;
    QVector<QVector<Bullet*>>m_magazineVector;

};

#endif // FLYER_H
