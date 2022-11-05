#ifndef CONFIG_H
#define CONFIG_H
#include<QWidget>
#include<QObject>
/*游戏配置*/
const double GAME_WIDTH=512;
const double GAME_HEIGHT=767;
const QString GAME_TITLE="飞机大战 v1.0";
const QString GAME_RES_PATH="D:\\QTprojects\\planeSmallWar\\x64\\Release\\res.rcc";
const QString GAME_ICON_PATH=":/images/icon.png";
/*地图配置*/
const double SCROLL_SPEED = 2;
const QString MAP1_PATH = ":/images/bg1.jpg";
const QString MAP2_PATH = ":/images/bg2.jpg";
const QString MAP3_PATH = ":/images/bg3.jpg";
//const MAP4_PATH ":/images/bg4.jpg";
//const MAP5_PATH ":/images/bg5.jpg";

/**飞机配置数据**/
const double BoxScaledRate = 0.5;
/*英雄配置数据*/
const double Hero_Speed = 0.5;
const double Shooting_Interval =200;  //英雄发射子弹的间隔;
const double Strafe_Interval = 100;
const double Hero1_Hp =100;           //英雄生命值;
const double ENEGY_MAX =10; //最大能量值;
const QString HERO1_PATH =":/images/hero1.png";
const QString HERO2_PATH =":/images/hero2.png";
const double Hero1_CollidingInjury=10000;
//技能
const double QuickShoot_Lastingmsc = 5000;
const double Invincible_Lastingmsc = 5000;
const double Strafe_Lastingmsc = 5000;
const double AnnularShoot_Lastingmsc = 5000;

/*敌机配置数据*/
//总生命值
const double Enemy1_Hp = 10;
const double Enemy2_Hp = 15;
const double Enemy3_Hp = 10;
const double Enemy4_Hp = 10;
const double Enemy5_Hp = 10;
const double Enemy6_Hp = 10;
//贴图
const QString ENEMY1_PATH = ":/images/enemy1.png";
const QString ENEMY2_PATH = ":/images/enemy2.png";
const QString ENEMY3_PATH = ":/images/enemy3.png";
const QString ENEMY4_PATH = ":/images/enemy4.png";
const QString ENEMY5_PATH = ":/images/enemy5.png";
const QString ENEMY6_PATH = ":/images/enemy6.png";
const QString EBULLET_PATH1 =":/images/ebullet1.png";//敌机子弹路径
const QString EBULLET_PATH2 =":/images/ebullet2.png"; //敌机子弹路径
//速度
const double Enemy1_Speed = 1;
const double Enemy2_Speed = 1;
const double Enemy3_Speed = 1;
const double Enemy4_Speed = 1;
const double Enemy5_Speed = 1;
const double Enemy6_Speed = 1;
//数量
const int Enemy1_Amount = 3;
const int Enemy2_Amount = 2;
const int Enemy3_Amount = 1;
//定时器
const double Enemy1_ShootingRate = 1000;
const double Enemy2_ShootingRate = 1500;
//碰撞伤害
const double Enemy1_CollidingInjury = 10;
const double Enemy2_CollidingInjury = 10;
const double Enemy3_CollidingInjury = 10;
const double Enemy4_CollidingInjury = 10;
const double Enemy5_CollidingInjury = 10;
const double Enemy6_CollidingInjury = 10;

//Boss信息
const double BOSS_Height =250;
const double BOSS_WIDth =250;
const QString BOSS_MOVIE =":/images/boss.gif";
//爆炸
const double BOMB_NUM =20;
const double BOMB_MAX =7;
const double BOMB_INTERVAL =10;
const QString BOMB_PATH =":/images/expload%1.png";

//音效
const QString SOUND_EXPLODE =":/images/bomb.wav";
const QString SOUND_BACKGROUND =":/images/metrohead.wav";
const QString SOUND_BULLET_HIT =":/images/Bullet_hit.wav";
const QString SOUND_BULLET_SHOOT= ":/images/Bullet_shoot.wav";
//开始菜单
const QString START1= ":/images/start1.png";
const QString START2= ":/images/start2.png";
const QString START3= ":/images/start3.png";
const QString LoadRoundSound_Path= ":/images/start.wav";
/*子弹*/
//贴图
const QString BULLET0_PATH =":/images/bullet0.png";
const QString BULLET1_PATH =":/images/bullet1.png";
const QString BULLET2_PATH =":/images/bullet2.png";
const QString BULLET3_PATH =":/images/bullet3.png";


//伤害
const double Blue_Damage = 2;
const double Red_Damage = 2;
const double Huge_Damage = 10000;
//发射角度
const double Blue_Angle = 90;
const double Red_Angle = 90;
const double Huge_Angle = 90;
//速度
const double Blue_Speed = 10;
const double Red_Speed = 5;
const double Huge_Speed = 5;
//数量
const int Huge_Amount = 4;
/*----------------------------*/
//补给包
//速度
const double Invincible_Speed = 2;
//数量
const int Supply1_Amount = 3;
const int Supply2_Amount = 2;
const int Supply3_Amount = 1;
/*主界面*/
/*定时器*/
const double GAME_RATE=10;//帧定时器
const double EnemyGeneratingRate =3000;
const double SupplyGeneratingRate = 10000;
/*血条长度*/
const int HpBar1Length=40;
#endif // CONFIG_H

