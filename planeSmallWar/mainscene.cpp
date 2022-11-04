#include "mainscene.h"
#include<QIcon>
#include<qtextedit.h>
#include<qlabel.h>
#include<QMovie>
#include<QPropertyAnimation>
#include<QSoundEffect>

#include<QLabel>
#include<QScreen>
#include<QPainter>
#include<QKeyEvent>
#include<enemy1.h>
#include<enemy2.h>
#include<QRgb>
Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    ui.setupUi(this);
    initScene();
    //loadSound();
    connectFirst();
}
Widget::~Widget()
{
    if(!m_painter)delete m_painter;
}
void Widget::initScene()
{
    //窗口
    setFixedSize(GAME_WIDTH,GAME_HEIGHT);
    setWindowTitle(GAME_TITLE);
    setWindowIcon(QIcon(GAME_ICON_PATH));
    QLabel *Hp_label = new QLabel(this);
    Hp_label->setGeometry(QRect(2,GAME_HEIGHT-30,20,20));
    Hp_label->setText("HP:");
    Hp_label->setFont(QFont("DOUYU"));
    Hp_label->setStyleSheet(QString("*{color:rgb(244,96,108)}"));
    //定时器
    m_timer.setInterval(GAME_RATE);
    m_enemyTimer.setInterval(EnemyGeneratingRate);
    m_supplyTimer.setInterval(SupplyGeneratingRate);
    //UI
    m_pauseMenu=new pauseScene(this);
    m_pauseMenu->setGeometry((width()-m_pauseMenu->width())/2,(height()-m_pauseMenu->height())/2,m_pauseMenu->width(),m_pauseMenu->height());
    m_pauseMenu->hide();
    m_loseMenu = new LoseMenu(this);
    m_loseMenu->setGeometry((this->width()-m_loseMenu->width())/2,(this->height()-m_loseMenu->height())/2,m_loseMenu->width(),m_loseMenu->height());
    m_loseMenu->hide();
    //    parentBlackPic();

    m_hero=new HeroPlane1(this);
    m_painter=new QPainter;
    prepareEnemyVector();
    prepareSupplyVector();
    //    qApp->setStyleSheet(QString("QPushButton {width:130px;height:30px;border:0px;background-repeat:no-repeat;}"));
}

void Widget::playGame()
{
    //    //播放背景音乐
    //    bgPlayer->play();
    //    //启动定时器
    startAllTimer();
}


//void Widget::on_HeroDie()
//{
//    //音乐停止
//   this->bgPlayer->stop();
//    //弹出结算界面

//}

void Widget::updatePosition()
{
    //地图滚动
    m_map.mapPosition();
    //玩家飞机移动
    operateHeroFly();
    //玩家子弹移动
    m_hero->shootBullet();
    //敌机移动
    moveEnemyAndBullet();
    //补给包移动
    moveSupplies();
}

void Widget::generateEnemy()
{

    if(!m_enemiesVector.length())
    {
        QMessageBox::warning(this,"错误","未初始化敌机数组");
        return;
    }
    int index =rand()%m_enemiesVector.length();
    for(auto it = m_enemiesVector[index].begin();it!=m_enemiesVector[index].end();it++)
    {
        if(!(*it)->isAlive())
        {
            (*it)->born();
            return;
        }
    }
}

void Widget::generateSupply()
{

    if(!m_suppliesVector.length())
    {
        QMessageBox::warning(this,"错误","未初始化敌机数组");
        return;
    }
    int index =rand()%m_suppliesVector.length();
    for(auto it = m_suppliesVector[index].begin();it!=m_suppliesVector[index].end();it++)
    {
        if(!(*it)->isAlive())
        {
            (*it)->born();
            return;
        }
    }
}


void Widget::prepareEnemyVector()
{
    for(int i = 0;i<Enemy1_Amount;i++)
    {
        m_enemies1.push_back(new Enemy1(this));
    }
    for(int i = 0;i<Enemy2_Amount;i++)
    {
        m_enemies2.push_back(new Enemy2(this));
    }

    m_enemiesVector.push_back(m_enemies1);
    m_enemiesVector.push_back(m_enemies2);
}

void Widget::prepareSupplyVector()
{
    for(int i = 0;i<Supply1_Amount;i++)
    {
        m_supplies1.push_back(new SupplyInvincible(this));
    }

    m_suppliesVector.push_back(m_supplies1);
}

void Widget::detectBulletHitEnemies(Bullet *bullet)
{
    for(auto it = m_enemiesVector.begin();it!=m_enemiesVector.end();it++ )
    {
        for(auto sIt = (*it).begin();sIt!=(*it).end();sIt++)
        {
            if((*sIt)->isAlive()&&bullet->rect().intersects((*sIt)->rect()))
            {
                (*sIt)->setPreviousHp((*sIt)->previousHp()-bullet->damage());
                bullet->die();
                if((*sIt)->previousHp()<=0)
                {
                    (*sIt)->die();
                }
            }
        }
    }
}

void Widget::detectEnemiesHitHero()
{
    for(auto it = m_enemiesVector.begin();it!=m_enemiesVector.end();it++ )
    {
        for(auto sIt = (*it).begin();sIt!=(*it).end();sIt++)
        {
            if((*sIt)->isAlive())
            {
                detectEnemyHitHero(*sIt);
                detectHeroCrashEnemy(*sIt);
            }
        }
    }
}

void Widget::detectHeroGetSupply()
{
    //supplies1
    for(auto it = m_suppliesVector[0].begin();it!=m_suppliesVector[0].end();it++)
    {

    }
    //supplies2
}

void Widget::detectHeroCrashEnemy(Enemy *enemy)
{
    if(enemy->rect().intersects(m_hero->rect()))
    {
        enemy->setPreviousHp(enemy->previousHp()-m_hero->collidingInjury());
        m_hero->setPreviousHp(m_hero->previousHp()-enemy->collidingInjury());
        if(enemy->previousHp()<=0)
        {
            enemy->die();
        }
        if(m_hero->previousHp()<=0)
        {
            m_hero->die();
        }
    }
}


void Widget::detectEnemyHitHero(Enemy *sIt)
{
    for(auto it = (*sIt).magazineVector().begin();it!=(*sIt).magazineVector().end();it++ )
    {
        for(auto sIt = (*it).begin();sIt!=(*it).end();sIt++)
        {
            if((*sIt)->isAlive()&&m_hero->isAlive()&&(*sIt)->rect().intersects(m_hero->rect()))
            {
                (*sIt)->die();
                m_hero->setPreviousHp(m_hero->previousHp()-(*sIt)->damage());
                if(m_hero->previousHp()<=0)
                {
                    m_hero->die();
                }
                qDebug()<<"Widgt::detectEnemyHitHero.EnemyhitHero"<<m_hero->previousHp();
            }
        }
    }
}

bool Widget::playing() const
{
    return m_playing;
}

void Widget::setPlaying(bool newPlaying)
{
    m_playing = newPlaying;
}



//void Widget::moveEvent(QMoveEvent *event)
//{
//    //this->parentWidget()->setGeometry(this->geometry());
//}

void Widget::paintEvent(QPaintEvent *)
{
    m_painter->begin(this);
    m_painter->drawPixmap(0,m_map.m_map_1_posY,m_map.m_map1);//地图
    m_painter->drawPixmap(0,m_map.m_map_2_posY,m_map.m_map2);
    if(m_hero->isAlive())//英雄
    {
        m_painter->drawPixmap(m_hero->x(),m_hero->y(),m_hero->picture());
        m_painter->drawRect(m_hero->rect());
    }
    drawHeroBullets();//英雄子弹
    drawEnemiesAndBullets();//敌机
    drawSupplies();//补给包

    //画英雄血条
    drawHeroHpBar();
    drawEnemiesHpBar();
    //    //画爆炸
    //    for (int i = 0; i < 20; i++)
    //    {
    //        if (!ex[i].m_free)
    //        {
    //            painter.drawPixmap(ex[i].m_x, ex[i].m_y, ex[i].m_pixArr[ex[i].m_index]);
    //        }
    //    }
    //    //画boss
    //    if(bossTime)
    //    {
    //       painter.drawPixmap(boss->getPos(),boss->m_pic);
    //}


    //    }


    m_painter->end();
}

void Widget::startAllTimer()
{
    m_timer.start();
    m_enemyTimer.start();
    m_supplyTimer.start();
}

void Widget::keyPressEvent(QKeyEvent *event)
{
    if(event->key()==Qt::Key_Left)
    {
        my_vector.StateofMoveKeys[0]=QString("pressed");
    }
    if(event->key()==Qt::Key_Up)
    {
        my_vector.StateofMoveKeys[1]=QString("pressed");
    }
    if(event->key()==Qt::Key_Down)
    {
        my_vector.StateofMoveKeys[2]=QString("pressed");
    }
    if(event->key()==Qt::Key_Right)
    {
        my_vector.StateofMoveKeys[3]=QString("pressed");
    }
    if(event->key()==Qt::Key_Shift)//低速移动键，参照東方project机制
    {
        my_vector.StateofMoveKeys[4]=QString("pressed");
    }
    if(event->key()==Qt::Key_A)
    {
        my_vector.StateofMoveKeys[5]=QString("pressed");
    }
    if(event->key()==Qt::Key_W)
    {
        my_vector.StateofMoveKeys[6]=QString("pressed");
    }
    if(event->key()==Qt::Key_S)
    {
        my_vector.StateofMoveKeys[7]=QString("pressed");
    }
    if(event->key()==Qt::Key_D)
    {
        my_vector.StateofMoveKeys[8]=QString("pressed");
    }
    //暂停
    if(event->key()==Qt::Key_Escape)
    {
        pauseStaff();
    }

}



void Widget::keyReleaseEvent(QKeyEvent *event)
{
    if(event->key()==Qt::Key_Left)
    {
        this->my_vector.StateofMoveKeys[0]=QString("unpressed");
    }
    if(event->key()==Qt::Key_Right)
    {
        this->my_vector.StateofMoveKeys[3]=QString("unpressed");
    }
    if(event->key()==Qt::Key_Up)
    {
        this->my_vector.StateofMoveKeys[1]=QString("unpressed");
    }
    if(event->key()==Qt::Key_Down)
    {
        this->my_vector.StateofMoveKeys[2]=QString("unpressed");
    }
    if(event->key()==Qt::Key_Shift)//低速移动键，参照東方project机制
    {
        this->my_vector.StateofMoveKeys[4]=QString("unpressed");
    }
    if(event->key()==Qt::Key_A)
    {
        this->my_vector.StateofMoveKeys[5]=QString("unpressed");
    }
    if(event->key()==Qt::Key_W)
    {
        this->my_vector.StateofMoveKeys[6]=QString("unpressed");
    }
    if(event->key()==Qt::Key_S)
    {
        this->my_vector.StateofMoveKeys[7]=QString("unpressed");
    }
    if(event->key()==Qt::Key_D)
    {
        this->my_vector.StateofMoveKeys[8]=QString("unpressed");
    }
    if(event->key()==Qt::Key_T)
    {
        m_hero->OnQuickShoot();
    }
}

void Widget::pauseStaff()
{

    if(playing())
    {
        setPlaying(false);
        m_pauseMenu->show();
        //this->m_widget->show();
        //bgm暂停
        //bgPlayer->pause();

    }
    else
    {
        setPlaying(true);
        m_pauseMenu->hide();
        //this->m_widget->hide();
        //bgPlayer->play();
    }
}

//碰撞检测
void Widget::collisionDetection()
{
    //英雄子弹撞击敌机
    detectHeroHitEnemies();
    //敌机子弹和本体撞击英雄
    detectEnemiesHitHero();
    //英雄撞击补给包


}

void Widget::detectHeroHitEnemies()
{
    for(auto it =m_hero->magazineVector().begin();it!=m_hero->magazineVector().end();it++ )
    {
        for(auto sIt = (*it).begin();sIt!=(*it).end();sIt++)
        {
            if((*sIt)->isAlive())
            {
                detectBulletHitEnemies(*sIt);
            }
        }
    }
}

//void Widget::eneExpload(int i)
//{
//    //加分数
//    hero.m_score++;
//    ene[i].m_alive = false;
//    for (int k = 0; k < 20; k++)
//    {   //爆炸动画
//        if (ex[k].m_free)
//        {
//            expload->play();
//            ex[k].m_free = false;
//            ex[k].m_x = ene[i].m_x+ene[i].m_pic.width() / 2;
//            ex[k].m_y = ene[i].m_y+ene[i].m_pic.height() / 2;
//            break;
//        }
//    }
//}

//void Widget::loadSound()
//{
//    //爆炸
//    expload=new QSoundEffect(this);
//    expload->setSource(QUrl::fromLocalFile(SOUND_EXPLODE));
//    expload->setVolume(1.0f);
//    //打击
//    hit = new QSoundEffect(this);
//    hit->setSource(QUrl::fromLocalFile(SOUND_BULLET_HIT));
//    hit->setVolume(0.7);
//    //背景音乐
//    bgPlayer=new QMediaPlayer(this);
//    audiooutput = new QAudioOutput(this);
//    audiooutput->setVolume(100);
//    bgPlayer->setSource(QUrl("qrc:/images/cyberthug.wav"));
//    bgPlayer->setAudioOutput(audiooutput);
//    bgPlayer->setLoops(QMediaPlayer::Infinite);
//    //失败
//    lose=new QSoundEffect(this);
//    lose->setSource(QUrl::fromLocalFile(":/images/lose.wav"));
//    lose->setVolume(1.0f);
//    lose1=new QSoundEffect(this);
//    lose1->setSource(QUrl::fromLocalFile(":/images/lose1.wav"));
//    lose1->setVolume(1.0f);
//}

void Widget::connectFirst()
{
    //返回开始菜单
    connect(this->m_pauseMenu,&pauseScene::backToStart,this,[=](){emit this->backToStart();});
    connect(this->m_loseMenu,&LoseMenu::backToStart,this,[=](){emit this->backToStart();});
    //重开
    connect(this->m_loseMenu,&LoseMenu::restart,this,[=](){emit this->restart();});
    connect(this->m_pauseMenu,&pauseScene::restart,this,[=](){emit this->restart();});
    //产生objects信号
    connect(&this->m_enemyTimer, &QTimer::timeout, this,&Widget::generateEnemy);
    connect(&this->m_supplyTimer, &QTimer::timeout, this,&Widget::generateSupply);
    //connect(this,SIGNAL(HeroDie()),this,SLOT(on_HeroDie()));
    //帧信号
    connect(&this->m_timer,&QTimer::timeout,this,[=]()
    {
        if(!playing())return;
        updatePosition();
        collisionDetection();
        //显示分数
        //显示能量
        update();
    });
}

//void Widget::die_movie()
//{
//    QLabel *lab=new QLabel(this);
//    QMovie * die = new QMovie(this);
//    die->setFileName(":/images/HeroDie.gif");
//    lab->setGeometry(hero.m_x,hero.m_y,hero.m_pic.width(),hero.m_pic.height());
//    lab->setMovie(die);
//    die->start();
//    lab->show();
//    die->setSpeed(75);
//    QObject::connect(die, &QMovie::frameChanged, [=](int frameNumber) {
//    // GIF 动画执行一次就结束
//    if (frameNumber == die->frameCount()-1) {
//    die->stop();
//    }
//    });

//}

//void Widget::parentBlackPic()
//{
//            this->m_widget = new QWidget(this);
//            m_widget->resize (this->width(), this->height());
//            m_widget->move (0,0);
//            QPalette pal(m_widget->palette());
//            m_widget->setStyleSheet("background-color:rgba(0, 0, 0, 20%);");
//            m_widget->setAutoFillBackground(true);
//            m_widget->setPalette(pal);
//            m_widget->hide();
//}

//void Widget::showEnergy()
//{
//    this->ui.label_energy->setText(QString::number(this->m_energy));
//}

//void Widget::showKillAll()
//{
//    this->ui.lab_killall->setText(QString::number(hero.killAll));
//}
void Widget::drawHeroBullets()
{
    for(auto it = m_hero->magazineVector().begin();it!=m_hero->magazineVector().end();it++ )
    {
        for(auto sIt = (*it).begin();sIt!=(*it).end();sIt++)
        {
            if((*sIt)->isAlive())
            {
                m_painter->drawPixmap((*sIt)->x(),(*sIt)->y(),(*sIt)->picture().width(),(*sIt)->picture().height(),(*sIt)->picture());
                m_painter->drawRect((*sIt)->rect());
            }
        }
    }
}

void Widget::drawEnemiesAndBullets()
{
    for(auto it = m_enemiesVector.begin();it!=m_enemiesVector.end();it++ )
    {
        for(auto sIt = (*it).begin();sIt!=(*it).end();sIt++)
        {
            drawEnemieBullets(*sIt);
            if((*sIt)->isAlive())
            {
                m_painter->drawPixmap((*sIt)->x(),(*sIt)->y(),(*sIt)->picture().width(),(*sIt)->picture().height(),(*sIt)->picture());
                m_painter->drawRect((*sIt)->rect());
            }
        }
    }
}

void Widget::drawEnemieBullets(Enemy* enemy)
{
    for(auto it = enemy->magazineVector().begin();it!=enemy->magazineVector().end();it++ )
    {
        for(auto sIt = (*it).begin();sIt!=(*it).end();sIt++)
        {
            if((*sIt)->isAlive())
            {
                //qDebug()<<"Widget::drawEnemiesBullets"<<(*sIt)->x()<<(*sIt)->y();
                m_painter->drawPixmap((*sIt)->x(),(*sIt)->y(),(*sIt)->picture().width(),(*sIt)->picture().height(),(*sIt)->picture());
                m_painter->drawRect((*sIt)->rect());
            }
        }
    }
}

void Widget::drawSupplies()
{
    for(auto it = m_suppliesVector.begin();it!=m_suppliesVector.end();it++ )
    {
        for(auto sIt = (*it).begin();sIt!=(*it).end();sIt++)
        {
            if((*sIt)->isAlive())
            {
                //qDebug()<<"Widget::drawEnemiesBullets"<<(*sIt)->x()<<(*sIt)->y();
                m_painter->drawPixmap((*sIt)->x(),(*sIt)->y(),(*sIt)->picture().width(),(*sIt)->picture().height(),(*sIt)->picture());
                m_painter->drawRect((*sIt)->rect());
            }
        }
    }
}

void Widget::drawHeroHpBar()
{
    if(!m_hero->isAlive())return;
    QBrush green_brush(QColor(25,202,173));
    QBrush red_brush(QColor("red"));
    float rate = 1.0*m_hero->previousHp()/m_hero->totalHp();
    if(rate>=0.5)
    {
        m_painter->setBrush(green_brush);
    }
    else
    {
        m_painter->setBrush(red_brush);
    }
    m_painter->drawRect(30,GAME_HEIGHT-30,100*rate,20);
}

void Widget::drawEnemiesHpBar()
{
    QBrush white_brush(QColor("yellow"));
    m_painter->setBrush(white_brush);
    for(auto it = m_enemiesVector.begin();it!=m_enemiesVector.end();it++)
    {
        for(auto sIt = (*it).begin();sIt!=(*it).end();sIt++)
        {
            if((*sIt)->isAlive())
            {
                float rate = 1.0*(*sIt)->previousHp()/(*sIt)->totalHp();
                m_painter->drawRect((*sIt)->x(),(*sIt)->y()+(*sIt)->picture().height(),(*sIt)->totalHp()*10*rate,6);
            }
        }
    }
}
void Widget::operateHeroFly()
{
    this->my_vector.GenerateVector();
    int isShiftPressed=this->my_vector.StateofMoveKeys[4]==QString("pressed")?1:0;
    int deltax=qFloor(this->my_vector.Vx*100000.0)/(10000+isShiftPressed*30000);
    int deltay=qFloor(this->my_vector.Vy*100000.0)/(10000+isShiftPressed*30000);
    double newX =this->m_hero->x()+deltax*Hero_Speed;
    double newY =this->m_hero->y()+deltay*Hero_Speed;
    if(newX<0||newX>GAME_WIDTH-m_hero->picture().width()||newY<0||newY>GAME_HEIGHT-m_hero->picture().height())
    {
        return;
    }
    this->m_hero->setPos(newX,newY);
    m_hero->moveRect();
}

void Widget::moveEnemyAndBullet()
{
    for(auto it = m_enemiesVector.begin();it!=m_enemiesVector.end();it++)
    {
        for(auto sIt = (*it).begin();sIt!=(*it).end();sIt++)
        {
            (*sIt)->shootBullet();
            if(!(*sIt)->isAlive())continue;
            (*sIt)->fly();

        }
    }
}

void Widget::moveSupplies()
{
    for(auto it = m_suppliesVector.begin();it!=m_suppliesVector.end();it++)
    {
        for(auto sIt = (*it).begin();sIt!=(*it).end();sIt++)
        {
            if(!(*sIt)->isAlive())continue;
            (*sIt)->fly();
        }
    }
}

