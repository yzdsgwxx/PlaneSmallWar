#include "startmenu.h"
#include "ui_startmenu.h"
#include<QPainter>
#include<QTime>
#include<QKeyEvent>
#include<QScreen>
startMenu::startMenu(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::startMenu)
{
    ui->setupUi(this);
    loadRoundSound=new QSoundEffect(); loadRoundSound->setSource(QUrl::fromLocalFile(LoadRoundSound_Path));loadRoundSound->setVolume(1.0f);
    initialSecene();
    initConnect();
}

startMenu::~startMenu()
{
    delete ui;
}

void startMenu::initialSecene()
{
    //    设置固定尺寸
    QRect screenRect = QGuiApplication::primaryScreen()->geometry();
    double screenWidth = screenRect.width();
    double screenHeight = screenRect.height();
    this->setGeometry(screenWidth/2-GAME_WIDTH/2,screenHeight/2-GAME_HEIGHT/2,GAME_WIDTH,GAME_HEIGHT);
    setFixedSize(GAME_WIDTH,GAME_HEIGHT);
    //设置窗口标题
    this->setWindowTitle(GAME_TITLE);
    //设置窗口图标
    this->setWindowIcon(QIcon(GAME_ICON_PATH));
    //用于返回主菜单

}

void startMenu::initConnect()
{

    //点击开始按钮
    connect(ui->btn_start,&QPushButton::clicked,this,[=](){
        loadRoundSound->play();
        this->w =new Widget;
        this->w->setGeometry(this->geometry());
        w->show();
        this->hide();
        w->playGame();
        //连接返回按钮
        connect(this->w,&Widget::backToStart,this,&startMenu::onBackToStart);
        //连接重启按钮
        connect(this->w,&Widget::restart,this,&startMenu::onRestart);
});
}
void startMenu::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);
    QPainter painter(this);
    painter.drawPixmap(0,0,QPixmap(MAP2_PATH));
}

void startMenu::keyPressEvent(QKeyEvent *event)
{
    if(event->key()==Qt::Key_Return)
    {
        emit ui->btn_start->clicked();
    }
    QWidget::keyPressEvent(event);
}

void startMenu::onBackToStart()
{
    this->setGeometry(this->w->geometry());
    this->show();
    this->w->hide();
    delete this->w;
    this->w=NULL;
}

void startMenu::onRestart()
{
    delete this->w;
    this->w=NULL;
    emit this->ui->btn_start->clicked();
}

