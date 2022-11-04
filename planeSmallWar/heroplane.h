#ifndef HEROPLANE_H
#define HEROPLANE_H
#include<Plane.h>
class HeroPlane: public Plane
{
    Q_OBJECT
public:
    HeroPlane(QWidget * parent=nullptr);


    void born()override;

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
    bool killAll();
    bool invincible();
    bool quickShoot() const;
    bool strafe() const;
    bool annularShoot() const;
    void setStrafe(bool newStrafe);
    void setQuickShoot(bool newQuickShoot);
    void setAnnularShoot(bool newAnnularShoot);
    void setKillAll(bool newKillAll);
    void setInvincible(bool newInvincible);

private:
    //技能
    bool m_killAll;
    bool m_invincible;
    bool m_quickShoot;
    bool m_strafe;//(strafe v.扫射)
    bool m_annularShoot;


};

#endif // HEROPLANE_H
