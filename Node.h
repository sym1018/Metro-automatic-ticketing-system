#ifndef NODE_H
#define NODE_H

#include <iostream> 
#include <string>

class Node
{
public:


    Node(std::string station,int data = 0);//���캯��,�Գ���ָ����Ϊ���Σ���ָ�������Ϊ���������ɸ��� 
    Node(char data=0); 
    //Node();
	Node* prior;//ָ��ǰһ�����
	std::string date;//�����Ϣ 
	Node* p_next;//ָ���һ�����
    std::string m_station;//
    char m_cData;   //����,վ����
    bool m_bIsVisited;//�Ƿ񱻷��ʵı�ʶ
};
#endif
