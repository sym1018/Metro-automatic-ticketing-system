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
    bool addNode(Node *pNode);  //��ͼ�м��붥�㡢�ڵ�
    void resetNode();           //���ö���  ������Ϊû�з��ʹ�
    bool setValueToMatrixForDirectedGraph(int row, int col, int val = 1);  //Ϊ����ͼ�����ڽӾ���
    bool setValueToMatrixForUndirectedGraph(int row, int col, int val = 1); //Ϊ����ͼ�����ڽӾ���
    void printMatrix();         //��ӡ�ڽӾ���
    void depthFirstTraverse(int nodeIndex);         //������ȱ���
    void breadthFirstTraverse(int nodeIndex);       //������ȱ��� 2����
    //void depth_search(int start,int end,int *b,int start2,int a);
    int dfs(int a, int v);
    bool getValueFromMatrix(int row, int col, int &val);    //�Ӿ����л�ȡȨֵ

private:

    void breadthFirstTraverseImpl(vector<int> preVec);      //������ȱ���ʵ�ֺ���

private:
    int m_iCapacity;    //ͼ���������ɵĶ�����
    int m_iNodeCount;   //�Ѿ���ӵĶ������
    Node *m_pNodeArray; //������Ŷ�������
    int *m_pMatrix;     //��������ڽӾ���  �����õ�һά����
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
