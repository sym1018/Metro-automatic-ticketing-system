#ifndef M_LIST_H
#define M_LIST_H
#include "Node.h"

class m_list
{
	public:
		m_list();
		~m_list();
		m_list(int& n,Node *p_p,Node *p_r,std::string *a_data);//�вι��캯��������Ĳ���Ϊ������Ľ��Ϊn��,����һ��ͷβ 
		int getlistsize();//��ȡ������ĳ���
		void traverselist();//��������
		void insertnode(int  position, int  date);//�������ָ��λ�ò�����
		void deletenode(int position);//Ҫɾ���Ľ��λ��
		void m_research (Node *a_head,Node *a_rear);//��ѯͷָ�룬βָ�루δ��ɣ� 
		Node* m_head;
		Node* m_rear;
	protected:
		
};

#endif
