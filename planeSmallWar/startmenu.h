#ifndef STARTMENU_H
#define STARTMENU_H
#include"config.h"
#include <QWidget>
#include"QSoundEffect"
#include"mainscene.h"
namespace Ui {
class startMenu;
}

class startMenu : public QWidget
{
    Q_OBJECT

public:
    explicit startMenu(QWidget *parent = nullptr);
    ~startMenu();
private:
    QSoundEffect * loadRoundSound;
    Widget * w;
public:
    void initialSecene();
    void initConnect();
    void paintEvent(QPaintEvent *event)override;
    void keyPressEvent(QKeyEvent *event) override;
public slots:
    void onBackToStart();
    void onRestart();
private:
    Ui::startMenu *ui;
};

#endif // STARTMENU_H
