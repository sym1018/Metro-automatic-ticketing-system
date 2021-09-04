#include "Graph.h"
#include <cstring>
#include <iostream>
using namespace std;

int min_step = 10000;//最小步数 
int book[50][50];//标记是否访问过 
int my_x=1000;
int my_y=1000;

Graph::Graph(int capacity)
{
	
    m_iCapacity = capacity;//总结点数 
    m_iNodeCount = 0;//有效结点数 
    m_pNodeArray = new Node[m_iCapacity];//结点类型，结点存储空间 
    m_pMatrix = new int[m_iCapacity*m_iCapacity];//矩阵，表示边，int内为空间大小 
    memset(m_pMatrix, 0, sizeof(int)*m_iCapacity*m_iCapacity);//将矩阵中所有值赋为0 
}
Graph::~Graph()
{
    delete []m_pNodeArray;//释放结点空间 
    delete []m_pMatrix;//释放边所占空间 
}
//向图中加入节点， 
bool Graph::addNode(Node *pNode)
{
    if (pNode == NULL)
    {
        return false;//加入结点失败
		cout<<"你输入了一个空结点";
    }
    m_pNodeArray[m_iNodeCount].m_cData = pNode->m_cData;//将新节点中数据放入原结点数组尾部 
    m_pNodeArray[m_iNodeCount].m_station = pNode->m_station;//将新节点中数据放入原结点数组尾部 
    m_iNodeCount++;
    return true;
}
//重置顶点   都设置为没有访问过
void  Graph::resetNode()
{
    for (int i = 0; i < m_iNodeCount; i++)
    {
        m_pNodeArray[i].m_bIsVisited = false;
    }
}
//为有向图设置邻接矩阵，传入所在矩阵的行，列，权重 
bool  Graph::setValueToMatrixForDirectedGraph(int row, int col, int val)
{
    if (row < 0 || row >= m_iCapacity || col < 0 || col >= m_iCapacity)
    {
        return false;
        cout<<"行列超出范围"; 
    }
    m_pMatrix[row*m_iCapacity + col] = val;//单向
    return true;
}
//为无向图设置邻接矩阵
bool  Graph::setValueToMatrixForUndirectedGraph(int row, int col, int val)
{
    if (row < 0 || row >= m_iCapacity || col < 0 || col >= m_iCapacity)
    {
        return false;
        cout<<"行列超出范围"; 
    }
    m_pMatrix[row*m_iCapacity + col] = val;
    m_pMatrix[col*m_iCapacity + row] = val;//双向，实对称矩阵 
    return true;
}
//打印邻接矩阵
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
//深度优先遍历
void  Graph::depthFirstTraverse(int nodeIndex)
{
    int value = 0;
    cout<<m_pNodeArray[nodeIndex].m_station<<" ";
    m_pNodeArray[nodeIndex].m_bIsVisited = true;
    for (int i = 0; i < m_iCapacity; i++)
    {
        getValueFromMatrix(nodeIndex, i, value);//得到权值
        if (value != 0)//两点间有连接
        {
            if (m_pNodeArray[i].m_bIsVisited)//是否访问过
            {
                continue;
            }
            else
            {
                depthFirstTraverse(i);//递归
            }
        }
        else
        {
            continue;
        }
    }
}
//深度优先搜索 
/*void depth_search(int start,int end,int *b,int start2,int a)
{
	if (start==end)
	{
		start=start2;
	}
	int value = 0;//连接标识 
	m_pNodeArray[start].m_bIsVisited = true;
	for (int i = 0; i < m_iCapacity; i++)
	{
		getValueFromMatrix(nodeIndex, i, value);//得到权值
		if (value != 0)//两点间有连接
        {
			if (m_pNodeArray[i].m_bIsVisited)//已访问 
			{
	            continue;
	        }
	        else
	        {
	        	a=value+a;//路径长度 
	            depth_search(i,end,b,start2,a);//递归
	        }
        } 
	}
}*/

//前两个传参为目标位置，其后两个为开始地址，最后两个为步数与最短路径数传参地址 
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
	int *P = new int[m_iCapacity];//用来存储得到的最短路径
	int *D = new int[m_iCapacity];//用于存储由a到其它路径的长度
	const int INFINITY = 65535;
	int *final  = new int[m_iCapacity];//保存结点是否已访问过
	for (int i = 0; i < m_iCapacity; ++i)//初始化
	{
		D[i] = g[a][i];//路径长度
		P[i] = a;//由此可“叶落归根”
		final[i] = 0;
	}
	final[a] = 1;//不访问起点
	for (int i = 1; i < m_iCapacity; ++i)
	{
			int min = INFINITY;//当前的最短路径
			for (int w = 0; w < m_iCapacity; ++w)//取最距离a最近的点v
			{
				if ((final[w] == 0) && (D[w] < min))
				//如果存在更短的路径，替换
				{
					v = w;
					min = D[w];
				}
			}
			final[v] = 1;
			for (int w = 0; w < m_iCapacity; ++w)
			//如果v是最短路径上的点，加到P[]中
			{
				if ((final[w] == 0) && (min + g[v][w] < D[w]))
				{
					D[w] = min + g[v][w];
					P[w] = v;//从a到w最近路径，是v
				}
			}
	}
	cout<<D[t]<<endl;
	return D[t];
 
}

//从矩阵中获取权值，输入行，列，读取值的变量地址 
bool  Graph::getValueFromMatrix(int row, int col, int &val)
{
    if (row < 0 || row >= m_iCapacity || col < 0 || col >= m_iCapacity)
    {
        return false;
    }
    val = m_pMatrix[row*m_iCapacity + col];
    return true;
}

//广度优先遍历  比深度复杂些   一层放一个数组，按照数组里面存放的数据再次访问
void  Graph::breadthFirstTraverse(int nodeIndex)
{
    vector<int> curVec;
    cout<<m_pNodeArray[nodeIndex].m_cData<<" ";
    m_pNodeArray[nodeIndex].m_bIsVisited = true;

    curVec.push_back(nodeIndex);
    breadthFirstTraverseImpl(curVec);
}

//广度优先遍历实现函数
void  Graph::breadthFirstTraverseImpl(vector<int> preVec)
{
    int value = 0;
    vector<int> curVec;

    for (int i = 0; i < (int)preVec.size(); i++)
    {
        //当前节点所有相连的，就是一层一层的
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
    //preVec层的所有下一层curVec已经被找到，再次递归找这层的
    if (curVec.size() != 0)
    {
        breadthFirstTraverseImpl(curVec);
    }
    else
    {
        return;
    }
} 
