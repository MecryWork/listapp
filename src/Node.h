// Node.h: interface for the CNode class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_NODE_H__FB363617_8D8B_42E0_B6BB_CABF740A279B__INCLUDED_)
#define AFX_NODE_H__FB363617_8D8B_42E0_B6BB_CABF740A279B__INCLUDED_

#include "String.h"	// Added by ClassView
#include "StdAfx.h"
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CNode
{
friend ostream& operator<<(ostream &out,const CNode *pObj);
friend istream& operator>>(istream &in,CNode *pObj);

public:
	CNode();
	virtual ~CNode();

	bool operator== (const char *pszName);
	bool operator== (const CString pStrName);

	int CopyNode(const CNode *pNode);
public:
	CNode *m_pPre;
	CNode *m_pNext;

private:
	CString m_strName;
	CString m_strAddr;
	int m_nId;
};

#endif // !defined(AFX_NODE_H__FB363617_8D8B_42E0_B6BB_CABF740A279B__INCLUDED_)
