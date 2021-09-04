#include "chufa.h"

ChuFa::ChuFa(QWidget *parent) : QWidget(parent)
{
    label.setParent(this);
    label.resize(350,100);
    label.setText("您确定从此站出发？");
    QFont ft;
    ft.setPointSize(20);
    label.setFont(ft);
    label.move(80,10);
    button_can.setParent(this);
    button_ok.setParent(this);
    button_ok.setText("确定");
    button_can.setText("取消");
    button_ok.move(80,200);
    button_can.move(280,200);
    connect(&button_ok,&QPushButton::clicked,this,&ChuFa::button_ok_click);
    connect(&button_can,&QPushButton::clicked,this,&ChuFa::button_can_click);
}
void ChuFa::button_ok_click(){
    KaiGuan::cf=1;
    KaiGuan::dd=0;
    this->close();
}
void ChuFa::button_can_click(){
    KaiGuan::cf=0;
    KaiGuan::dd=0;
    this->close();
}
