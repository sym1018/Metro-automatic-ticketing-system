#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include "chufa.h"
#include "kaiguan.h"
#include "daoda.h"
#include "Graph.h"

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();
    ChuFa chufa;
    DaoDa daoda;


    //Graph graph;
private slots:

    void on_pushButton_89_clicked();

    void on_pushButton_88_clicked();

    void on_pushButton_41_clicked();

    void on_pushButton_87_clicked();

    void on_pushButton_86_clicked();

    void on_pushButton_85_clicked();

    void on_pushButton_84_clicked();

    void on_pushButton_83_clicked();

    void on_pushButton_18_clicked();

    void on_pushButton_51_clicked();

    void on_pushButton_57_clicked();

    void on_pushButton_58_clicked();

    void on_pushButton_59_clicked();

    void on_pushButton_60_clicked();

    void on_pushButton_61_clicked();

    void on_pushButton_62_clicked();

    void on_pushButton_63_clicked();

    void on_pushButton_64_clicked();

    void on_pushButton_65_clicked();

    void on_pushButton_66_clicked();

    void on_pushButton_67_clicked();

    void on_pushButton_68_clicked();

    void on_pushButton_69_clicked();

    void on_pushButton_70_clicked();

    void on_pushButton_29_clicked();

    void on_pushButton_71_clicked();

    void on_pushButton_72_clicked();

    void on_pushButton_73_clicked();

    void on_pushButton_74_clicked();

    void on_pushButton_75_clicked();

    void on_pushButton_76_clicked();

    void on_pushButton_77_clicked();

    void on_pushButton_78_clicked();

    void on_pushButton_79_clicked();

    void on_pushButton_80_clicked();

    void on_pushButton_81_clicked();

    void on_pushButton_82_clicked();

    void on_pushButton_94_clicked();

    void on_pushButton_93_clicked();

    void on_pushButton_92_clicked();

    void on_pushButton_91_clicked();

    void on_pushButton_90_clicked();

    void on_pushButton_40_clicked();

    void on_pushButton_42_clicked();

    void on_pushButton_43_clicked();

    void on_pushButton_44_clicked();

    void on_pushButton_45_clicked();

    void on_pushButton_46_clicked();

    void on_pushButton_47_clicked();

    void on_pushButton_14_clicked();

    void on_pushButton_52_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_50_clicked();

    void on_pushButton_49_clicked();

    void on_pushButton_33_clicked();

    void on_pushButton_32_clicked();

    void on_pushButton_31_clicked();

    void on_pushButton_30_clicked();

    void on_pushButton_20_clicked();

    void on_pushButton_48_clicked();

    void on_pushButton_53_clicked();

    void on_pushButton_54_clicked();

    void on_pushButton_55_clicked();

    void on_pushButton_56_clicked();

    void on_pushButton_25_clicked();

    void on_pushButton_34_clicked();

    void on_pushButton_35_clicked();

    void on_pushButton_36_clicked();

    void on_pushButton_39_clicked();

    void on_pushButton_38_clicked();

    void on_pushButton_37_clicked();

    void on_pushButton_9_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_10_clicked();

    void on_pushButton_11_clicked();

    void on_pushButton_16_clicked();

    void on_pushButton_15_clicked();

    void on_pushButton_13_clicked();

    void on_pushButton_12_clicked();

    void on_pushButton_19_clicked();

    void on_pushButton_17_clicked();

    void on_pushButton_21_clicked();

    void on_pushButton_22_clicked();

    void on_pushButton_23_clicked();

    void on_pushButton_24_clicked();

    void on_pushButton_26_clicked();

    void on_pushButton_27_clicked();

    void on_pushButton_28_clicked();

private:
    Ui::Widget *ui;
};

#endif // WIDGET_H
