// String.h: interface for the CString class.
#ifndef _CSTRING_H_
#define _CSTRING_H_

#include "StdAfx.h"

class CString
{
friend ostream& operator<<(ostream &out,const CString &pStr);
friend istream& operator>>(istream &in,CString &pStr);

public:
	CString();
	CString(const char *pStr);
	CString(const CString &r);

	~CString();

	int SetStr(const char *pStr);

	char* GetStr()const;
	int GetLen()const;

	CString& operator =(const CString &obj);
	CString& operator =(const char *Str);
	char& operator[](int nIdex);

	bool operator==(const char *pStr);
	bool operator==(const CString &obj);

	friend bool operator==(const char *pStr,const CString &obj);

private:
	int Copy(const char *pStr,int nLen = 0);
	int GetLen(const char *pStr);

private:
	char *m_pStr;
	int m_nLenth;
};

#endif
