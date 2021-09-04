#include "m_init.h"


m_init::m_init()
{
    //pMap = new Graph(11);
    std::string pn[11]={"A1","B1","C1","D1","E1","F1","G1","H1","I1","J1","K1"};//站名
    int a_s[11]={0,1,2,3,4,5,6,7,8,9,10};//编号
    //std::string a_data[7]={"A1","51"};//路站名
    Node *pNode[11]={NULL};

    for(int i=0;i<11;i++)//添加节点
        {
            pNode[i] = new Node(pn[i],a_s[i]);
            pMap->addNode(pNode[i]);
        }

        //无向图 输入队列，权值默认
        pMap->setValueToMatrixForUndirectedGraph(0,1,3);
        pMap->setValueToMatrixForUndirectedGraph(0,6,7);
        pMap->setValueToMatrixForUndirectedGraph(0,8,2);
        pMap->setValueToMatrixForUndirectedGraph(1,2,1);
        pMap->setValueToMatrixForUndirectedGraph(1,8,2);
        pMap->setValueToMatrixForUndirectedGraph(2,3,3);
        pMap->setValueToMatrixForUndirectedGraph(2,6,6);
        pMap->setValueToMatrixForUndirectedGraph(2,9,1);
        pMap->setValueToMatrixForUndirectedGraph(3,4,5);
        pMap->setValueToMatrixForUndirectedGraph(3,7,4);
        pMap->setValueToMatrixForUndirectedGraph(3,10,1);
        pMap->setValueToMatrixForUndirectedGraph(4,5,4);
        pMap->setValueToMatrixForUndirectedGraph(4,7,7);
        pMap->setValueToMatrixForUndirectedGraph(4,10,5);
        pMap->setValueToMatrixForUndirectedGraph(5,6,20);
        pMap->setValueToMatrixForUndirectedGraph(5,9,15);
        pMap->setValueToMatrixForUndirectedGraph(8,9,1);
        pMap->setValueToMatrixForUndirectedGraph(9,10,3);
        pMap->setValueToMatrixForUndirectedGraph(6,7,2);


}
