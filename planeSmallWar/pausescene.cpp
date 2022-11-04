#include "pausescene.h"
#include "ui_pausescene.h"
#include<config.h>
#include<QPainter>
#include<QTimer>
#include<QDebug>
#include<startmenu.h>
#include<mainscene.h>
pauseScene::pauseScene(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::pauseScene)
{

    ui->setupUi(this);
    connect(ui->btn_backToStart,&QPushButton::clicked,[=](){emit this->backToStart();});
    connect(ui->btn_restart,&QPushButton::clicked,[=](){emit this->restart();});
}
pauseScene::~pauseScene()
{
    delete ui;
}
