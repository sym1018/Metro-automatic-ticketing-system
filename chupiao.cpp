#include "chupiao.h"

ChuPiao::ChuPiao(QWidget *parent) : QWidget(parent)
{
    label.setParent(this);
    label.resize(680,150);
    QFont ft;
    ft.setPointSize(20);
    label.setFont(ft);
    label.move(20,10);
}
