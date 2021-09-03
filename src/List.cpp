#include "List.h"

CList::CList()
{
	m_pHead = NULL;
	m_pEnd = NULL;
	m_nLenth = 0;
}

CList::CList(CList &cList)
{
	if(NULL != m_pHead) {
		CNode *pTemp = cList.m_pHead;
		m_nLenth = 0;
		m_pHead = NULL;
		m_pEnd = NULL;
		CNode *pPos = m_pHead;
		while(NULL != pTemp) {
			CNode *pNode = new CNode;
			pNode->m_pNext = NULL;
			pNode->m_pPre = NULL;
			pNode->CopyNode(pTemp);
			if(NULL == m_pHead) {
				m_pHead = pNode;
				m_pEnd = pNode;
			} else {
				m_pEnd->m_pNext = pNode;
				pNode->m_pPre = m_pEnd;
				m_pEnd = pNode;
			}
			pTemp = pTemp->m_pNext;
		}
		m_pEnd = pPos;
	}
	m_nLenth = cList.m_nLenth;
}

CList::~CList()
{
	ClearList();
}

CList& CList::operator=(CList *pHead)
{
	pHead->m_pHead = m_pHead;
	m_nLenth = 0;
	return *this;
}

CNode* CList::operator[](int nIndex)
{
	if(NULL != m_pHead)
	{
		CNode *pNode = m_pHead;
		for(int i = 0; i < nIndex;i++) {
			if (NULL == pNode) {
				cout<<"NO FIND"<<endl;
				return NULL;
			}
			pNode = pNode->m_pNext;
		}
		return pNode;
	}
	return NULL;
}

ostream& operator<<(ostream &out,const CList &cList)
{
	if(NULL != cList.m_pHead) {
		CNode *pTemp = cList.m_pHead;
		while(NULL != pTemp) {
			cout<<pTemp;
			pTemp = pTemp->m_pNext;
		}
	}
	return out;
}

CList& CList::operator =(const CList &cList)
{
	if(NULL != cList.m_pHead) {
		CNode *pTemp = cList.m_pHead;
		m_nLenth = 0;
		m_pHead = NULL;
		m_pEnd = NULL;
		CNode *pPos = cList.m_pHead;
		while(NULL != pTemp) {
			CNode *pNode = new CNode;
			pNode->m_pNext = NULL;
			pNode->m_pPre = NULL;
			pNode->CopyNode(pTemp);
			if(NULL == m_pHead) {
				m_pHead = pNode;
				m_pEnd = pNode;
			}
			else {
				m_pEnd->m_pNext = pNode;
				pNode->m_pPre = m_pEnd;
				m_pEnd = pNode;
			}
			pTemp = pTemp->m_pNext;
		}
		m_pEnd = pPos;
	}
	m_nLenth = cList.m_nLenth;

	return *this;
}

CNode* CList::CreateNode()
{
	CNode *pNode = new CNode;
	m_nLenth++;
	cin>>pNode;

	return pNode;
}

int CList::CreateList()
{
	if(NULL == m_pHead) {
		CNode *pTemp = CreateNode();
		m_pHead = pTemp;
		m_pEnd = pTemp;
		return 0;
	}
	return -1;
}

int CList::EndAddNode()
{
	if(NULL != m_pHead) {
		CNode *pTemp = m_pHead;

		while(NULL != pTemp->m_pNext) {
			pTemp = pTemp->m_pNext;
		}

		CNode *pNode = CreateNode();

		pNode->m_pPre = pTemp;
		pTemp->m_pNext = pNode;
		m_pEnd = pNode;
		return 0;
	}
	return -1;
}

int CList::HeadAddNode()
{
	if(NULL != m_pHead) {
		CNode *pTemp = m_pHead;

		CNode *pNode = CreateNode();

		pNode->m_pPre = pTemp;
		pTemp->m_pNext = pNode;
		m_pHead = pNode;

		return 0;
	}
	return -1;
}

int CList::ShowList()
{
	if(NULL != m_pHead) {
		CNode *pTemp = m_pHead;

		while(NULL != pTemp)
		{
			cout<<pTemp;
			pTemp = pTemp->m_pNext;
		}
		return 0;
	}
	cout<<"NO POINT"<<endl;
	return -1;
}


int CList::Modify(const char *szBuf)
{
	if(NULL != m_pHead) {
		CNode *pTemp = m_pHead;
		while(NULL != pTemp)
		{
			if(*pTemp == szBuf) {
				cout<<"INPUT INFO"<<endl;
				cin>>pTemp;
				cout<<"SUCCESS MDIFY"<<endl;
				return 0;
			}
			pTemp = pTemp->m_pNext;
		}
		cout<<"NO FIND"<<endl;
		return 0;
	}
	return -1;
}

CNode* CList::FindNode(const char *szBuf)
{
	if(NULL != m_pHead) {
		CNode *pTemp = m_pHead;

		while(NULL != pTemp) {
			if(*pTemp == szBuf) {
				cout<<"SUCCESS FIND"<<endl;
				return pTemp;
			}
			pTemp = pTemp->m_pNext;
		}
		cout<<"NO FIND"<<endl;
		return NULL;
	}
	cout<<"NO FIND"<<endl;
	return NULL;
}

int CList::DeleteNode(CNode *pNode)
{
	if(NULL != m_pHead) {
		CNode *pTemp = m_pHead;

		if(NULL == pNode) {
			cout<<"NO POINT"<<endl;
			return -2;
		}
		if(NULL == pNode->m_pPre) {
			if(NULL == pNode->m_pNext) {
				m_pHead = NULL;
				m_pEnd = NULL;
			}
			m_pHead = pNode->m_pNext;
			pNode->m_pPre = NULL;
		}
		else if(NULL == pNode->m_pNext) {
			m_pEnd = pNode->m_pPre;
			pNode->m_pPre->m_pNext = NULL;
		}
		else {
			pNode->m_pPre->m_pNext = pNode->m_pNext;
			pNode->m_pNext->m_pPre = pNode->m_pPre;
		}
		m_nLenth--;
		delete pNode;
	}
	return -1;
}
int CList::ClearList()
{
	if(NULL != m_pHead) {
		CNode *pNode = m_pHead;
		while(NULL != m_pHead) {
			pNode = m_pHead->m_pNext;
			DeleteNode(m_pHead);
			m_pHead = pNode;
		}
		cout<<"CLEARLIST FINSH"<<endl;
		return 0;
	}
	return -1;
}


int CList::InsertNode(CNode *pPos)
{
	if(NULL == m_pHead) {
		return -1;
	}
	CNode *pNode = CreateNode();

	int n = 0;

	cout<<"1.Head 2.End"<<endl;
	cin>>n;

	if(1 == n) {
		if(NULL == pPos->m_pPre) {
			m_pHead = pNode;
		} else {
			pNode->m_pPre = pPos->m_pPre;
			pPos->m_pPre->m_pNext = pNode;
		}
			pNode->m_pNext = pPos;
			pPos->m_pPre = pNode;

	}
	else if(2 == n) {
		if(NULL == pPos->m_pNext) {
			m_pEnd = pNode;
		} else {
			pNode->m_pNext = pPos;
			pPos->m_pNext->m_pPre = pNode;

		}
			pPos->m_pNext = pNode;
			pNode->m_pPre = pPos;

	} else {
		cout<<"error input"<<endl;
	}

	return 0;

}
int CList::GetListLen()
{
	return m_nLenth;
}