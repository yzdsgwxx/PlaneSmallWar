#ifndef FLYER_H
#define FLYER_H
#include <QObject>
#include<QtWidgets>
#include<QPoint>
#include<config.h>
#include<QWidget>
#include<QCamera>
class Flyer : public QWidget
{
    Q_OBJECT
public:
    explicit Flyer(QWidget *parent = nullptr);
public:
    virtual void born();
    virtual void fly();
    virtual void die();
    void reborn();
public:
    bool isAlive() const;
    QPixmap picture() const;
    double x() const;
    double y() const;
    unsigned int speed() const;

    void setAlive(bool alive);
    void setPicture(const QString & picPath);
    void setPicture(const QPixmap & other);
    void setPos(int x,int y);
    void setX(int x);
    void setY(int y);
    void setSpeed(double speed);
    void moveRect();
    void setRectSize();

    void reportError(const QString & str);



    const QRect &rect() const;
    void setRect(const QRect &newRect);

    bool initialed() const;
    void setInitialed(bool newInitialed);

private:
    bool m_alive=false;
    QPixmap m_picture;
    QRect m_rect;
    double m_x;
    double m_y;
    unsigned int m_speed;

    bool m_initialed;

signals:

};

#endif // FLYER_H
