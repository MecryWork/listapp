#ifndef _LIST_h_
#define _LIST_h_

#include "Node.h"
#include "StdAfx.h"
class CList
{
friend ostream& operator<<(ostream &out,const CList &cList);

public:
	CList();
	CList(CList &cList);
	~CList();

	int CreateList();
	int EndAddNode();
	int HeadAddNode();
	int Modify(const char *szBuf);
	int ShowList();
	int DeleteNode(CNode *pNode);
	int ClearList();
	CNode* FindNode(const char *szBuf);
	int InsertNode(CNode *pPos);
	int GetListLen();

	CNode* operator[](int nIndex);
	CList& operator=(CList *pHead);
	CList& operator =(const CList &cList);

private:
	CNode* CreateNode();
	int m_nLenth;
	CNode *m_pHead;
	CNode *m_pEnd;
};

#endif
