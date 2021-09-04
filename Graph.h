#ifndef GRAPH_H
#define GRAPH_H
#include <vector>
using namespace std;
#include "Node.h"
class Graph
{
public:
    Graph(int capacity);
    ~Graph();
    bool addNode(Node *pNode);  //向图中加入顶点、节点
    void resetNode();           //重置顶点  都设置为没有访问过
    bool setValueToMatrixForDirectedGraph(int row, int col, int val = 1);  //为有向图设置邻接矩阵
    bool setValueToMatrixForUndirectedGraph(int row, int col, int val = 1); //为无向图设置邻接矩阵
    void printMatrix();         //打印邻接矩阵
    void depthFirstTraverse(int nodeIndex);         //深度优先遍历
    void breadthFirstTraverse(int nodeIndex);       //广度优先遍历 2部分
    //void depth_search(int start,int end,int *b,int start2,int a);
    int dfs(int a, int v);
    bool getValueFromMatrix(int row, int col, int &val);    //从矩阵中获取权值

private:

    void breadthFirstTraverseImpl(vector<int> preVec);      //广度优先遍历实现函数

private:
    int m_iCapacity;    //图中最多可容纳的顶点数
    int m_iNodeCount;   //已经添加的顶点个数
    Node *m_pNodeArray; //用来存放顶点数组
    int *m_pMatrix;     //用来存放邻接矩阵  这里用的一维数组
};

#endif // !Graph_H
/*class Graph
{
	public:
		Graph();
	protected:
};

#endif
*/
