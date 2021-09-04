#ifndef CHUFA_H
#define CHUFA_H
#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include "kaiguan.h"
class ChuFa : public QWidget
{
    Q_OBJECT
public:
    explicit ChuFa(QWidget *parent = nullptr);
    QPushButton button_ok;//确定按钮
    QPushButton button_can;//取消按钮
    QLabel label;//加个标签
    void button_can_click();//声明槽函数
    void button_ok_click();
signals:

public slots:
};

#endif // CHUFA_H
