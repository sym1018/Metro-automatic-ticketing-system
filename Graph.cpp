#include "Graph.h"
#include <cstring>
#include <iostream>
using namespace std;

int min_step = 10000;//��С���� 
int book[50][50];//����Ƿ���ʹ� 
int my_x=1000;
int my_y=1000;

Graph::Graph(int capacity)
{
	
    m_iCapacity = capacity;//�ܽ���� 
    m_iNodeCount = 0;//��Ч����� 
    m_pNodeArray = new Node[m_iCapacity];//������ͣ����洢�ռ� 
    m_pMatrix = new int[m_iCapacity*m_iCapacity];//���󣬱�ʾ�ߣ�int��Ϊ�ռ��С 
    memset(m_pMatrix, 0, sizeof(int)*m_iCapacity*m_iCapacity);//������������ֵ��Ϊ0 
}
Graph::~Graph()
{
    delete []m_pNodeArray;//�ͷŽ��ռ� 
    delete []m_pMatrix;//�ͷű���ռ�ռ� 
}
//��ͼ�м���ڵ㣬 
bool Graph::addNode(Node *pNode)
{
    if (pNode == NULL)
    {
        return false;//������ʧ��
		cout<<"��������һ���ս��";
    }
    m_pNodeArray[m_iNodeCount].m_cData = pNode->m_cData;//���½ڵ������ݷ���ԭ�������β�� 
    m_pNodeArray[m_iNodeCount].m_station = pNode->m_station;//���½ڵ������ݷ���ԭ�������β�� 
    m_iNodeCount++;
    return true;
}
//���ö���   ������Ϊû�з��ʹ�
void  Graph::resetNode()
{
    for (int i = 0; i < m_iNodeCount; i++)
    {
        m_pNodeArray[i].m_bIsVisited = false;
    }
}
//Ϊ����ͼ�����ڽӾ��󣬴������ھ�����У��У�Ȩ�� 
bool  Graph::setValueToMatrixForDirectedGraph(int row, int col, int val)
{
    if (row < 0 || row >= m_iCapacity || col < 0 || col >= m_iCapacity)
    {
        return false;
        cout<<"���г�����Χ"; 
    }
    m_pMatrix[row*m_iCapacity + col] = val;//����
    return true;
}
//Ϊ����ͼ�����ڽӾ���
bool  Graph::setValueToMatrixForUndirectedGraph(int row, int col, int val)
{
    if (row < 0 || row >= m_iCapacity || col < 0 || col >= m_iCapacity)
    {
        return false;
        cout<<"���г�����Χ"; 
    }
    m_pMatrix[row*m_iCapacity + col] = val;
    m_pMatrix[col*m_iCapacity + row] = val;//˫��ʵ�Գƾ��� 
    return true;
}
//��ӡ�ڽӾ���
void  Graph::printMatrix()
{
    for (int i = 0; i < m_iCapacity; i++)
    {
        for (int k = 0; k < m_iCapacity; k++)
        {
            cout<<m_pMatrix[i*m_iCapacity+k]<<" ";
        }
        cout<<endl;
    }
}
//������ȱ���
void  Graph::depthFirstTraverse(int nodeIndex)
{
    int value = 0;
    cout<<m_pNodeArray[nodeIndex].m_station<<" ";
    m_pNodeArray[nodeIndex].m_bIsVisited = true;
    for (int i = 0; i < m_iCapacity; i++)
    {
        getValueFromMatrix(nodeIndex, i, value);//�õ�Ȩֵ
        if (value != 0)//�����������
        {
            if (m_pNodeArray[i].m_bIsVisited)//�Ƿ���ʹ�
            {
                continue;
            }
            else
            {
                depthFirstTraverse(i);//�ݹ�
            }
        }
        else
        {
            continue;
        }
    }
}
//����������� 
/*void depth_search(int start,int end,int *b,int start2,int a)
{
	if (start==end)
	{
		start=start2;
	}
	int value = 0;//���ӱ�ʶ 
	m_pNodeArray[start].m_bIsVisited = true;
	for (int i = 0; i < m_iCapacity; i++)
	{
		getValueFromMatrix(nodeIndex, i, value);//�õ�Ȩֵ
		if (value != 0)//�����������
        {
			if (m_pNodeArray[i].m_bIsVisited)//�ѷ��� 
			{
	            continue;
	        }
	        else
	        {
	        	a=value+a;//·������ 
	            depth_search(i,end,b,start2,a);//�ݹ�
	        }
        } 
	}
}*/

//ǰ��������ΪĿ��λ�ã��������Ϊ��ʼ��ַ���������Ϊ���������·�������ε�ַ 
int Graph::dfs(int a, int v)
{
	
	int g[m_iCapacity][m_iCapacity];
	for (int i=0;i<m_iCapacity;i++)
	{
		for  (int j=0;j<m_iCapacity;j++)
		{
			g[i][j]=m_pMatrix[i*m_iCapacity + j];
			if (g[i][j]==0)
			{
				g[i][j]=65535;
			}
		} 
	}
    if (a==v)
    {
        return 0;
    }
	
	int t = v;
	int *P = new int[m_iCapacity];//�����洢�õ������·��
	int *D = new int[m_iCapacity];//���ڴ洢��a������·���ĳ���
	const int INFINITY = 65535;
	int *final  = new int[m_iCapacity];//�������Ƿ��ѷ��ʹ�
	for (int i = 0; i < m_iCapacity; ++i)//��ʼ��
	{
		D[i] = g[a][i];//·������
		P[i] = a;//�ɴ˿ɡ�Ҷ������
		final[i] = 0;
	}
	final[a] = 1;//���������
	for (int i = 1; i < m_iCapacity; ++i)
	{
			int min = INFINITY;//��ǰ�����·��
			for (int w = 0; w < m_iCapacity; ++w)//ȡ�����a����ĵ�v
			{
				if ((final[w] == 0) && (D[w] < min))
				//������ڸ��̵�·�����滻
				{
					v = w;
					min = D[w];
				}
			}
			final[v] = 1;
			for (int w = 0; w < m_iCapacity; ++w)
			//���v�����·���ϵĵ㣬�ӵ�P[]��
			{
				if ((final[w] == 0) && (min + g[v][w] < D[w]))
				{
					D[w] = min + g[v][w];
					P[w] = v;//��a��w���·������v
				}
			}
	}
	cout<<D[t]<<endl;
	return D[t];
 
}

//�Ӿ����л�ȡȨֵ�������У��У���ȡֵ�ı�����ַ 
bool  Graph::getValueFromMatrix(int row, int col, int &val)
{
    if (row < 0 || row >= m_iCapacity || col < 0 || col >= m_iCapacity)
    {
        return false;
    }
    val = m_pMatrix[row*m_iCapacity + col];
    return true;
}

//������ȱ���  ����ȸ���Щ   һ���һ�����飬�������������ŵ������ٴη���
void  Graph::breadthFirstTraverse(int nodeIndex)
{
    vector<int> curVec;
    cout<<m_pNodeArray[nodeIndex].m_cData<<" ";
    m_pNodeArray[nodeIndex].m_bIsVisited = true;

    curVec.push_back(nodeIndex);
    breadthFirstTraverseImpl(curVec);
}

//������ȱ���ʵ�ֺ���
void  Graph::breadthFirstTraverseImpl(vector<int> preVec)
{
    int value = 0;
    vector<int> curVec;

    for (int i = 0; i < (int)preVec.size(); i++)
    {
        //��ǰ�ڵ����������ģ�����һ��һ���
        for (int j = 0; j < m_iCapacity; j++)
        {
            getValueFromMatrix(preVec[i], j, value);
            if (value != 0)
            {
                if (m_pNodeArray[j].m_bIsVisited)
                {
                    continue;
                }
                else
                {
                    cout<<m_pNodeArray[j].m_cData<<" ";
                    m_pNodeArray[j].m_bIsVisited = true;

                    curVec.push_back(j);
                }
            }
            else
            {
                continue;
            }
        }
    }
    //preVec���������һ��curVec�Ѿ����ҵ����ٴεݹ�������
    if (curVec.size() != 0)
    {
        breadthFirstTraverseImpl(curVec);
    }
    else
    {
        return;
    }
} 
