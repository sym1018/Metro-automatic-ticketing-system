#ifndef DAODA_H
#define DAODA_H
#include <QWidget>
#include "m_init.h"
#include <QPushButton>
#include <QLabel>
#include "kaiguan.h"
#include "chupiao.h"
#include "Graph.h"

class DaoDa : public QWidget
{
    Q_OBJECT
public:
    explicit DaoDa(QWidget *parent = nullptr);
    QPushButton button_ok;//确定按钮
    QPushButton button_can;//取消按钮
    QLabel label;//加个标签
    ChuPiao chupiao;
    //Widget w();
    void button_can_click();//声明槽函数
    void button_ok_click();
signals:

public slots:
};

#endif // DAODA_H
