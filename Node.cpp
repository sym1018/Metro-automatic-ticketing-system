#include "Node.h"

/*Node::Node()
{    
	prior=NULL;
    m_bIsVisited = false;
}*/


Node::Node(char data)
{
    m_cData = data;
    prior=NULL;
    m_bIsVisited = false;
}
Node::Node(std::string station,int data)
{
	prior=NULL;
	m_station=station;
    m_cData = data;
    m_bIsVisited = false;
}
