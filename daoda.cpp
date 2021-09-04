#include "daoda.h"
//#include "widget.h"
#include <QString>
#include<cmath>//C语言是math.h
using namespace std;
DaoDa::DaoDa(QWidget *parent) : QWidget(parent)
{
    label.setParent(this);
    label.resize(350,100);
    label.setText("您确定到达此站？");
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
    connect(&button_ok,&QPushButton::clicked,this,&DaoDa::button_ok_click);
    connect(&button_can,&QPushButton::clicked,this,&DaoDa::button_can_click);
}
void DaoDa::button_ok_click(){
    m_init mi;
    int length1,length2;//出发站路长度，目的站路长度
    KaiGuan::cf=0;//改变开关状态
    KaiGuan::dd=1;
    mi.pMap->dfs(0,1);

    mi.pMap->getValueFromMatrix(KaiGuan::station_start,KaiGuan::station_rear,length1);//出发站所在路的长度，保存在length1中
    mi.pMap->getValueFromMatrix(KaiGuan::station_starte,KaiGuan::station_reare,length2);//目的站所在路的长度，保存在length2中
    this->close();
    int money;
    int a[4];
    int b[6]={KaiGuan::station_start,KaiGuan::station_rear,KaiGuan::station_location,KaiGuan::station_starte,KaiGuan::station_reare,KaiGuan::station_locatione};

    //int length1=abs(KaiGuan::station_start-KaiGuan::station_rear)+1;//出发站点长度
    //int length2=abs(KaiGuan::station_starte-KaiGuan::station_reare)+1; //目的站点长度
    if((KaiGuan::station_location)*(KaiGuan::station_locatione)!=0)//非交点
   {
        if ((KaiGuan::station_start==KaiGuan::station_starte)&&(KaiGuan::station_rear==KaiGuan::station_reare))//同路
        {
            money=abs(KaiGuan::station_location-KaiGuan::station_locatione);
        }
        else//结点不同路
        {
            if((KaiGuan::station_rear==KaiGuan::station_start)||(KaiGuan::station_reare==KaiGuan::station_starte))//存在仅一端连接
            {
                if ((KaiGuan::station_rear==KaiGuan::station_start)&&(KaiGuan::station_reare!=KaiGuan::station_starte))//一端连接到一端连接
                {
                    a[0]=mi.pMap->dfs(KaiGuan::station_start,KaiGuan::station_starte)+KaiGuan::station_location+KaiGuan::station_locatione;
                    a[1]=mi.pMap->dfs(KaiGuan::station_start,KaiGuan::station_reare)+KaiGuan::station_location+length2-KaiGuan::station_locatione;
                    if (a[0]>a[1])
                    {money=a[1];}
                    else
                    {money=a[0];}
                }
                else if((KaiGuan::station_rear!=KaiGuan::station_start)&&(KaiGuan::station_reare==KaiGuan::station_starte))//全连接到全连接
                {
                    a[0]=mi.pMap->dfs(KaiGuan::station_start,KaiGuan::station_starte)+KaiGuan::station_location+KaiGuan::station_locatione;
                    a[1]=mi.pMap->dfs(KaiGuan::station_rear,KaiGuan::station_reare)+length1-KaiGuan::station_location+KaiGuan::station_locatione;
                    if (a[0]>a[1])
                    {money=a[1];}
                    else
                    {money=a[0];}
                }
                else //((KaiGuan::station_rear==KaiGuan::station_start)&&(KaiGuan::station_reare==KaiGuan::station_starte))//一端连接到一端连接
                {
                    a[0]=mi.pMap->dfs(KaiGuan::station_start,KaiGuan::station_starte)+KaiGuan::station_location+KaiGuan::station_locatione;
                    money=a[0];
                }
            }
            else
            {
                a[0]=mi.pMap->dfs(KaiGuan::station_start,KaiGuan::station_starte)+KaiGuan::station_location+KaiGuan::station_locatione;
                a[1]=mi.pMap->dfs(KaiGuan::station_start,KaiGuan::station_reare)+KaiGuan::station_location+length2-KaiGuan::station_locatione;
                a[2]=mi.pMap->dfs(KaiGuan::station_rear,KaiGuan::station_starte)+length1-KaiGuan::station_location+KaiGuan::station_locatione;
                a[3]=mi.pMap->dfs(KaiGuan::station_rear,KaiGuan::station_reare)+length1-KaiGuan::station_location+length2-KaiGuan::station_locatione;
                for(int i = 0; i < 3; i++)
                {
                    for(int j = 0; j < 4 - i - 1; j++)
                    {
                        if(a[j] > a[j+1])
                            swap(a[j],a[j+1]);
                    }
                }
                money=a[0];
            }
        }

   }
    else if((KaiGuan::station_location==0)&&(KaiGuan::station_locatione==0))//两个均为交点
    {
        money=mi.pMap->dfs(KaiGuan::station_start,KaiGuan::station_starte);

    }

    else if((KaiGuan::station_location==0)&&(KaiGuan::station_locatione!=0))//其中一个为交点
    {
        if((KaiGuan::station_rear==KaiGuan::station_start)&&(KaiGuan::station_reare==KaiGuan::station_starte))//存在仅一端连接
        {
            a[0]=mi.pMap->dfs(KaiGuan::station_start,KaiGuan::station_starte)+KaiGuan::station_location+KaiGuan::station_locatione;
            money=a[0];
        }
        else
        {
            a[0]=mi.pMap->dfs(KaiGuan::station_start,KaiGuan::station_starte)+KaiGuan::station_locatione;
            //money=a[0];
            a[1]=mi.pMap->dfs(KaiGuan::station_start,KaiGuan::station_reare)+length2-KaiGuan::station_locatione;
            if(a[0]>a[1])
            {money=a[1];}
            else
            {money=a[0];}
        }
    }
    else if((KaiGuan::station_location!=0)&&(KaiGuan::station_locatione==0))//其中一个为交点
    {
        if((KaiGuan::station_rear==KaiGuan::station_start)&&(KaiGuan::station_reare==KaiGuan::station_starte))//存在仅一端连接
        {
            a[0]=mi.pMap->dfs(KaiGuan::station_start,KaiGuan::station_starte)+KaiGuan::station_location+KaiGuan::station_locatione;
            money=a[0];
        }
        else//全连接
        {
            a[2]=mi.pMap->dfs(KaiGuan::station_start,KaiGuan::station_starte)+KaiGuan::station_location;
            a[3]=mi.pMap->dfs(KaiGuan::station_rear,KaiGuan::station_reare)+length1-KaiGuan::station_location;
            if(a[2]>a[3])
            {money=a[3];}
            else
            {money=a[2];}
        }
    }
    else
    {
        a[0]=mi.pMap->dfs(KaiGuan::station_start,KaiGuan::station_starte)+KaiGuan::station_location+KaiGuan::station_locatione;
        a[1]=mi.pMap->dfs(KaiGuan::station_start,KaiGuan::station_reare)+KaiGuan::station_location+length2-KaiGuan::station_locatione;
        a[2]=mi.pMap->dfs(KaiGuan::station_rear,KaiGuan::station_starte)+length1-KaiGuan::station_location+KaiGuan::station_locatione;
        a[3]=mi.pMap->dfs(KaiGuan::station_rear,KaiGuan::station_reare)+length1-KaiGuan::station_location+length2-KaiGuan::station_locatione;
        for(int i = 0; i < 3; i++)
            {
                for(int j = 0; j < 4 - i - 1; j++)
                {
                    if(a[j] > a[j+1])
                        swap(a[j],a[j+1]);
                }
            }
        money=a[0];
    }

    if(money<2)
    {
    money=2;
    }

    if(money>10)
    {
    money=10;
    }
    QString money1;
    money1 =QString::number(money,10);
    QString str="确认出票:\n出发站:"+KaiGuan::name[KaiGuan::start1][KaiGuan::start2]+"-->"+"到达站:"+KaiGuan::name[KaiGuan::end1][KaiGuan::end2]+"\n票价:"+money1+"元";
    //QString str="\n票价"+money1;
    chupiao.label.setText(str);
    chupiao.setFixedSize(700,200);
    chupiao.show();
}
void DaoDa::button_can_click(){
    KaiGuan::cf=0;
    KaiGuan::dd=0;
    this->close();
}

