#ifndef SUPPLY_H
#define SUPPLY_H

#include<flyer.h>
class Supply : public Flyer
{
    Q_OBJECT
public:
    explicit Supply(QWidget *parent = nullptr);
    void born() override;
    void fly()override;
    double angle() const;
    void setAngle(double newAngle);

private:
    double m_angle;
signals:

};

#endif // SUPPLY_H
