#ifndef LOSEMENU_H
#define LOSEMENU_H

#include <QWidget>
#include<QPixmap>
namespace Ui {
class LoseMenu;
}

class LoseMenu : public QWidget
{
    Q_OBJECT

private:
    QPixmap backGround;
public:
    explicit LoseMenu(QWidget *parent = nullptr);
    ~LoseMenu();
    //设置显示分数
    void showScore(int score);
        void paintEvent(QPaintEvent *event)override;
signals:
    void backToStart();
    void restart();
private:
    Ui::LoseMenu *ui;
};

#endif // LOSEMENU_H
