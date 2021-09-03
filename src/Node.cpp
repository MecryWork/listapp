#include "StdAfx.h"
#include "Node.h"

CNode::CNode()
{
	m_pPre = NULL;
	m_pNext = NULL;
}

CNode::~CNode()
{
	m_nId = 0;
}

ostream& operator<<(ostream &out,const CNode *pObj)
{
	if(NULL != pObj)
	{
		cout<<"//////////////////////////////////////////"<<endl;
		cout<<"Name:";
		cout<<pObj->m_strName<<endl;
		cout<<"Addr:";
		cout<<pObj->m_strAddr<<endl;
		cout<<"nId :";
		cout<<pObj->m_nId<<endl;
		cout<<"//////////////////////////////////////////"<<endl;
	}

	return out;
}

istream& operator>>(istream &in,CNode *pObj)
{

	cout<<"Name:";
	cin>>pObj->m_strName;
	cout<<"Addr:";
	cin>>pObj->m_strAddr;
	cout<<"nId :";
	cin>>pObj->m_nId;

	return in;
}


bool CNode::operator== (const char *pszName)
{
	return m_strName == pszName;
}

bool CNode::operator== (const CString pStrName)
{
	return m_strName == pStrName;
}

int CNode::CopyNode(const CNode *pNode)
{
	if(NULL == pNode) {
		return -1;
	}
	m_strName = pNode->m_strName;
	m_strAddr = pNode->m_strAddr;
	m_nId = pNode->m_nId;

	return 0;
}

