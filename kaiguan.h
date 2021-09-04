#ifndef KAIGUAN_H
#define KAIGUAN_H
#include <QString>

class KaiGuan
{
public:
    KaiGuan();
    static int cf;
    static int dd;
    static int start1;
    static int start2;//记录起始点坐标
    static int station_start;
    static int station_location;
    static int station_rear;

    static int station_starte;
    static int station_locatione;
    static int station_reare;
    static int end1;
    static int end2;//记录到达点坐标
    static QString name[5][100];
};

#endif // KAIGUAN_H
