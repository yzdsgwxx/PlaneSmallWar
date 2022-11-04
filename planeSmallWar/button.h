#ifndef BUTTON_H
#define BUTTON_H
#include<QPushButton>
namespace Ui {
class Button;
}

class Button : public QPushButton
{
    Q_OBJECT

public:
    explicit Button(QWidget *parent = nullptr);
    ~Button();

private:
    Ui::Button *ui;
};

#endif // BUTTON_H
