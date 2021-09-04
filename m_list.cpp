#include "m_list.h"

using std::cout;
using std::cin;
using std::endl;

m_list::m_list()
{
	this->m_head = new Node;//this表示当前正在使用的类的对象,生成了一个新的结点，使链表的头结点指向这个结点 
	this->m_head->prior = m_head;//头结点的头指向自己，使用时需更改 
	this->m_head->date = "123";
	this->m_head->p_next = NULL;

}

//创建新链表函数的实现，头指针为图中一个结点 ,传入头部指针，尾部指针 
m_list::m_list(int &n,Node *p_p,Node *p_r,std::string *a_data)
{
	
	//首先创建一个头结点，注意如果调用有参构造，就不会调用无参构造
	this->m_head = new Node;//建立新结点，使本对象头指向新节点 
	this->m_head->prior = m_head;//新结点的头结点指向自己 
    this->m_head->date = "<123>";
	this->m_head->p_next = NULL;
	
	
	this->m_rear = new Node;
	this->m_rear->p_next = p_r;//新结点的尾结点指向图中结点
	this->m_rear->date = "<123>";
	this->m_rear->prior = NULL;
	

 
	Node* pnew;//用来存放新结点的值
	Node* ptemp;//这个结点的作用见下面的注释
	ptemp = this->m_head;//当前的尾结点，初值为链表的头结点 
	int i = n;
	while (i--)
	{
		pnew = new Node;//开辟在堆区
		pnew->prior = ptemp;
		//默认的头结点为第0个结点（指针指向第一个结点，头结点无数据）
		cout << "请输入第" << n - i << "个结点的值" << endl;
		//cin >> pnew->date;
		pnew->date=a_data[n-i-1];
		pnew->p_next = m_rear;//新生成的结点在最后一个最后一个指向头结点
		ptemp->p_next = pnew;//将新节点与前一个连接起来 
		//ptemp这个结点的作用是一直作为链表最后一个结点
		ptemp = pnew;//迭代 
	}
	m_head->prior = p_p;//头结点指向图中结点
	m_rear->prior = ptemp;//尾结点的头指向数据的尾 
}

m_list::~m_list()
{
}
//获取链表长度 
int m_list::getlistsize()
{
	int count = 0;
	int flag = 0;
	Node* p = this->m_head;//以头结点为结束标识，使用时使用尾结点 
	while ((p->p_next != m_rear)||flag==0)
	{
		flag = 1;
		count++;
		p = p->p_next;
	}
	return count;
}

//在指定位置后插入结点 
void m_list::insertnode(int  position, int date)
{
	//position代表在第几个结点后面插入新结点 
	int len = getlistsize();
	//判断插入位置是否大于现有链表长度 
	if ((position > len) || position < 0)//??position?len????0
	{
		cout << "插入位置非法!" << endl;
		exit(0);
	}
	else
	{
		Node* pnew = new Node;//要插入的结点 
		Node* ptemp = NULL;//
		ptemp = this->m_head;
		pnew->date = date;
		for (int i = 0; i < position; i++)
		{
			ptemp = ptemp->p_next;//找到要插入的结点位置 
		}
		//下面两行pnew的前后指向 
		pnew->prior = ptemp;
		pnew->p_next = ptemp->p_next;
 
		ptemp->p_next->prior = pnew;//
 
		ptemp->p_next = pnew;
	}
}

//删除指定结点 
void m_list::deletenode(int position)
{
	int len = getlistsize();
	if ((position > len) || position <= 0)//len????0
	{
		cout << "删除位置非法!" << endl;
		exit(0);
	}
	else
	{
		Node* p = this->m_head;
		for (int i = 0; i < position - 1; i++)
		{
			p = p->p_next;//找到要删除结点的前一个结点 
		}
		Node* p1 = p->p_next;//记录要删除的结点 
 
		p->p_next->p_next->prior = p;
 
		p->p_next = p->p_next->p_next;
 
		delete p1;
	}
}

//链表遍历 
void m_list::traverselist()
{
	Node* p = this->m_head;
	int flag = 0;
	int i = 0;
	while ((p->p_next != m_rear)||flag==0)
	{
		flag = 1;
		cout << "第" << ++i << "个结点的值为: " << p->p_next->date << endl;
		p = p->p_next;
	}
}




