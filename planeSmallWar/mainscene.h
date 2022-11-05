#ifndef WIDGET_H
#define WIDGET_H   //此处条件编译用于防止头文件重复包含。WIDGET_H是代表此份头文件已存在的标志，当这份文件被嵌套什么的在一个头文件中包含
//了两次，第一次会生成这个标志，第二次包含时这个标志已存在，不会再包含。
#include"config.h"
#include <QWidget>
#include<QTimer>
#include<map.h>
#include<heroplane1.h>
#include<movevector.h>
#include<pausescene.h>
#include<enemy.h>
#include<supplyinvincible.h>
#include<losemenu.h>
//#include<qmovie.h>
//#include<expload.h>
//#include<QSoundEffect>
//#include<QMediaPlayer>

//#include<QKeyEvent>
//#include<qmessagebox.h>


//#include<QImage>

//#include<boss.h>
//#include<QAudioOutput>

#include<ui_mainscene.h>
class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget* parent = nullptr);
    ~Widget();
public:
    void initScene();
    void connectFirst();
    void startAllTimer();
    void stopAllTimer();
    void gameOver();
    void killAll();
    void killAllStaff();
    //抄--方向移动
    void keyReleaseEvent(QKeyEvent *event) ;
    void keyPressEvent(QKeyEvent *event) ;
    void pauseStaff();
    //绘图
    void paintEvent(QPaintEvent *event);
    void drawHeroBullets();
    void drawEnemiesAndBullets();
    void drawEnemieBullets(Enemy *enemy);
    void drawSupplies();
    void drawHeroHpBar();
    void drawEnemiesHpBar();
    //更新所有游戏中元素的坐标
    void updatePosition();
    void operateHeroFly();
    void moveEnemyAndBullet();
    void moveSupplies();
    //产生Objects
    void generateEnemy();
    void generateSupply();
    void prepareEnemyVector();
    void prepareSupplyVector();
    //碰撞检测
    void collisionDetection();
    void detectHeroHitEnemies();
    void detectEnemiesHitHero();
    void detectHeroGetSupply();
    void detectHeroCrashEnemy(Enemy *enemy);
    void detectBulletHitEnemies(Bullet * bullet);
    void detectHugeBulletHitEnemies(Bullet * bullet);
    void detectEnemyHitHero(Enemy *sIt);

    //    void moveEvent(QMoveEvent *event) override;

    //    //鼠标移动事件
    //   // void mouseMoveEvent(QMouseEvent *event);
    //    //英雄子弹碰撞检测
    //    void heroBullCollision(Bullet bull[],int i);
    //    //数组中第i个敌人爆炸
    //    void eneExpload(int i);
    //    //加载音效
    //    void loadSound();


    //    //死亡动画
    //    void die_movie();
    //    //透明黑色遮罩
    //    void parentBlackPic();
    //    //显示能量
    //    void showEnergy();
    //    //显示清屏技能数
    //    void showKillAll();

    bool playing() const;
    void setPlaying(bool newPlaying);

private:
    //定时器
    QTimer m_timer;
    QTimer m_enemyTimer;
    QTimer m_supplyTimer;

    map m_map;
    HeroPlane * m_hero;
    //移动向量
    MoveVector my_vector;
    //敌机
    QVector<QVector<Enemy *>> m_enemiesVector;
    QVector<QVector<Supply *>> m_suppliesVector;
    QVector<Enemy*> m_enemies1;
    QVector<Enemy*>m_enemies2;
    //QVector<Enemy*>m_eneies3;
    QVector<Supply *> m_supplies1;

    //UI
    pauseScene * m_pauseMenu;
    LoseMenu * m_loseMenu;
    QPainter * m_painter;

    bool m_playing=1;
    //      //能量
    //      int m_energy = 0;
    //      //能量满
    //      bool m_Energy_enough=false;
    //      Boss * boss;

    //       //爆炸数组
    //       expload ex[20];
    //      //音效
    //         QSoundEffect *expload;
    //         QSoundEffect *hit;
    //         QMediaPlayer *bgPlayer;
    //         QAudioOutput * audiooutput;
    //         QSoundEffect *lose;
    //         QSoundEffect *lose1;
    //         //暂停
    //        //游戏结束
    //        bool gameover=0;
    //透明黑色背景
    // QWidget *m_widget;

signals:
    void backToStart();
    void restart();
public slots:
    //启动游戏
    void playGame();
    //英雄死亡
    //void on_HeroDie();
private:
    Ui::mainscene ui;
};
#endif // WIDGET_H
