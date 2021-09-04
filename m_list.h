#ifndef M_LIST_H
#define M_LIST_H
#include "Node.h"

class m_list
{
	public:
		m_list();
		~m_list();
		m_list(int& n,Node *p_p,Node *p_r,std::string *a_data);//有参构造函数，传入的参数为新链表的结点为n个,返回一个头尾 
		int getlistsize();//获取该链表的长度
		void traverselist();//遍历链表
		void insertnode(int  position, int  date);//在链表的指定位置插入结点
		void deletenode(int position);//要删除的结点位置
		void m_research (Node *a_head,Node *a_rear);//查询头指针，尾指针（未完成） 
		Node* m_head;
		Node* m_rear;
	protected:
		
};

#endif
