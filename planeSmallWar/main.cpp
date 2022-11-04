//#pragma comment( linker, "/subsystem:windows /entry:mainCRTStartup" )   //关闭控制台
#include <QApplication>
#include<QResource>
#include<config.h>
#include<startmenu.h>
#include<QTime>

int main(int argc, char *argv[])
{

    srand((unsigned)time(NULL));
    QApplication a(argc, argv);
    QResource::registerResource(GAME_RES_PATH);
    startMenu s;
    s.show();
    return a.exec();
}
