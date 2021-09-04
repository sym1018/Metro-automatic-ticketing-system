#include "m_list.h"

using std::cout;
using std::cin;
using std::endl;

m_list::m_list()
{
	this->m_head = new Node;//this��ʾ��ǰ����ʹ�õ���Ķ���,������һ���µĽ�㣬ʹ�����ͷ���ָ�������� 
	this->m_head->prior = m_head;//ͷ����ͷָ���Լ���ʹ��ʱ����� 
	this->m_head->date = "123";
	this->m_head->p_next = NULL;

}

//��������������ʵ�֣�ͷָ��Ϊͼ��һ����� ,����ͷ��ָ�룬β��ָ�� 
m_list::m_list(int &n,Node *p_p,Node *p_r,std::string *a_data)
{
	
	//���ȴ���һ��ͷ��㣬ע����������вι��죬�Ͳ�������޲ι���
	this->m_head = new Node;//�����½�㣬ʹ������ͷָ���½ڵ� 
	this->m_head->prior = m_head;//�½���ͷ���ָ���Լ� 
    this->m_head->date = "<123>";
	this->m_head->p_next = NULL;
	
	
	this->m_rear = new Node;
	this->m_rear->p_next = p_r;//�½���β���ָ��ͼ�н��
	this->m_rear->date = "<123>";
	this->m_rear->prior = NULL;
	

 
	Node* pnew;//��������½���ֵ
	Node* ptemp;//����������ü������ע��
	ptemp = this->m_head;//��ǰ��β��㣬��ֵΪ�����ͷ��� 
	int i = n;
	while (i--)
	{
		pnew = new Node;//�����ڶ���
		pnew->prior = ptemp;
		//Ĭ�ϵ�ͷ���Ϊ��0����㣨ָ��ָ���һ����㣬ͷ��������ݣ�
		cout << "�������" << n - i << "������ֵ" << endl;
		//cin >> pnew->date;
		pnew->date=a_data[n-i-1];
		pnew->p_next = m_rear;//�����ɵĽ�������һ�����һ��ָ��ͷ���
		ptemp->p_next = pnew;//���½ڵ���ǰһ���������� 
		//ptemp�������������һֱ��Ϊ�������һ�����
		ptemp = pnew;//���� 
	}
	m_head->prior = p_p;//ͷ���ָ��ͼ�н��
	m_rear->prior = ptemp;//β����ͷָ�����ݵ�β 
}

m_list::~m_list()
{
}
//��ȡ������ 
int m_list::getlistsize()
{
	int count = 0;
	int flag = 0;
	Node* p = this->m_head;//��ͷ���Ϊ������ʶ��ʹ��ʱʹ��β��� 
	while ((p->p_next != m_rear)||flag==0)
	{
		flag = 1;
		count++;
		p = p->p_next;
	}
	return count;
}

//��ָ��λ�ú������ 
void m_list::insertnode(int  position, int date)
{
	//position�����ڵڼ�������������½�� 
	int len = getlistsize();
	//�жϲ���λ���Ƿ�������������� 
	if ((position > len) || position < 0)//??position?len????0
	{
		cout << "����λ�÷Ƿ�!" << endl;
		exit(0);
	}
	else
	{
		Node* pnew = new Node;//Ҫ����Ľ�� 
		Node* ptemp = NULL;//
		ptemp = this->m_head;
		pnew->date = date;
		for (int i = 0; i < position; i++)
		{
			ptemp = ptemp->p_next;//�ҵ�Ҫ����Ľ��λ�� 
		}
		//��������pnew��ǰ��ָ�� 
		pnew->prior = ptemp;
		pnew->p_next = ptemp->p_next;
 
		ptemp->p_next->prior = pnew;//
 
		ptemp->p_next = pnew;
	}
}

//ɾ��ָ����� 
void m_list::deletenode(int position)
{
	int len = getlistsize();
	if ((position > len) || position <= 0)//len????0
	{
		cout << "ɾ��λ�÷Ƿ�!" << endl;
		exit(0);
	}
	else
	{
		Node* p = this->m_head;
		for (int i = 0; i < position - 1; i++)
		{
			p = p->p_next;//�ҵ�Ҫɾ������ǰһ����� 
		}
		Node* p1 = p->p_next;//��¼Ҫɾ���Ľ�� 
 
		p->p_next->p_next->prior = p;
 
		p->p_next = p->p_next->p_next;
 
		delete p1;
	}
}

//������� 
void m_list::traverselist()
{
	Node* p = this->m_head;
	int flag = 0;
	int i = 0;
	while ((p->p_next != m_rear)||flag==0)
	{
		flag = 1;
		cout << "��" << ++i << "������ֵΪ: " << p->p_next->date << endl;
		p = p->p_next;
	}
}




