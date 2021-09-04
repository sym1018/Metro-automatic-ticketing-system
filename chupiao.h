#ifndef CHUPIAO_H
#define CHUPIAO_H
#include <QWidget>
#include <QLabel>
class ChuPiao : public QWidget
{
    Q_OBJECT
public:
    explicit ChuPiao(QWidget *parent = nullptr);
    QLabel label;
signals:

public slots:
};

#endif // CHUPIAO_H
