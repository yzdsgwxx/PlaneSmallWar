#ifndef HEROPLANE_H
#define HEROPLANE_H
#include<Plane.h>
class HeroPlane: public Plane
{
    Q_OBJECT
public:
    HeroPlane(QWidget * parent=nullptr);


    void born()override;
    void die()override;
    void shootBullet()override;
    void prepareHugeBullet();
    void loadHugeBullet();
    void prepareMagazinesVector();
    void loadBullet();
    void loadStrafeBullet();
    //施放技能
    void OnKillAll();
    void OnInvincible();
    void OnQuickShoot();
    void OnStrafe();
    void OnAnnularShoot();

    //关闭技能
    void OffInvincible();
    void OffQuickShoot();
    void OffStrafe();
    void OffAnnularShoot();

    //getAndSet技能
    bool isInvincible() const;
    bool isQuickShoot() const;
    bool isStrafe() const;
    bool isAnnularShoot() const;
    int killAllAmount() const;
    int hugeBulletAmount() const;
    bool isStrafeOut() const;
    const QVector<Bullet *> &hugeMagazine() const;
    double strafeAngle() const;
    const QTimer &getStrafeTimer() const;
    void setStrafe(bool newStrafe);
    void setQuickShoot(bool newQuickShoot);
    void setAnnularShoot(bool newAnnularShoot);
    void setInvincible(bool newInvincible);
    void setKillAll(int newKillAll);
    void setHugeBulletAmount(int newHugeBulletAmount);
    void setStrafeAngle(double newStrafeAngle);
    void setStrafeTimer(double interval);
    void setStrafeOut(bool newStrafeOut);

    enum class BulletIndex{normal = 0,strafe = 1};
    Q_ENUM(BulletIndex)


private:
    //技能
    int m_killAll;
    int m_hugeBulletAmount;
    bool m_invincible;
    bool m_quickShoot;
    bool m_strafe;//(strafe v.扫射)
    bool m_annularShoot;
    QVector<Bullet*> m_hugeMagazine;
    QVector<Bullet*> m_strafeMagazine;
    QVector<Bullet*>m_blueMagazine;
    double m_strafeAngle;
    QTimer m_strafeTimer;
    bool m_strafeOut;
signals:
    bool heroDie();
};

#endif // HEROPLANE_H
