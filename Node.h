#ifndef NODE_H
#define NODE_H

#include <iostream> 
#include <string>

class Node
{
public:


    Node(std::string station,int data = 0);//构造函数,以常数指针作为传参，其指向的内容为常量，不可更改 
    Node(char data=0); 
    //Node();
	Node* prior;//指向前一个结点
	std::string date;//结点信息 
	Node* p_next;//指向后一个结点
    std::string m_station;//
    char m_cData;   //数据,站点编号
    bool m_bIsVisited;//是否被访问的标识
};
#endif
