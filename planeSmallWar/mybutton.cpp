#include "mybutton.h"
MyButton::MyButton(QWidget *parent) : QPushButton(parent)
{
    setStyleSheet(QString("*{background-repeat:no-repeat;}"));
}
