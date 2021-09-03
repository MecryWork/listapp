// String.cpp: implementation of the CString class.
//
//////////////////////////////////////////////////////////////////////

#include "StdAfx.h"
#include "String.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CString::CString()
{
	m_pStr = NULL;
	m_nLenth = 0;
}

CString::~CString()
{
	delete []m_pStr;
	m_nLenth = 0;
}

CString::CString(const char *pStr)
{
	m_pStr = NULL;
	m_nLenth = 0;
	m_nLenth = GetLen(pStr);
	Copy(pStr,m_nLenth);
}

CString::CString(const CString &r)
{
	m_pStr = NULL;
	m_nLenth = 0;

	if(0 != r.m_nLenth) {
		m_nLenth = r.m_nLenth;
		Copy(r.m_pStr);
	}
}


int CString::SetStr(const char *pStr)
{
	if(NULL != m_pStr) {
		delete []m_pStr;
		m_nLenth = 0;
	}
	Copy(pStr);
	return 0;
}

char* CString::GetStr()const
{
	 return m_pStr;
}

int CString::GetLen()const
{
	return m_nLenth;
}

int CString::Copy(const char *pStr,int nLen)
{
	if(NULL != m_pStr) {
		delete []m_pStr;
		m_nLenth = 0;
		return -1;
	}
	nLen = m_nLenth;
	if(0 == nLen) {
		nLen = GetLen(pStr);
	}
	m_pStr = new char[nLen+1];
	for(int i = 0;i <= nLen;i++) {
		m_pStr[i] = pStr[i];
	}

	return 0;
}

int CString::GetLen(const char *pStr)
{
	int nLen = 0;
	if(NULL != pStr) {
		while('\0' != *pStr++) {
			nLen++;
		}
	}

	return nLen;
}


CString& CString::operator =(const CString &obj)
{
	if(this != &obj) {
		if(NULL != m_pStr) {
			delete []m_pStr;
			m_nLenth = 0;
		}

		Copy(obj.m_pStr,obj.m_nLenth);
	}
	return *this;
}

CString& CString::operator =(const char *Str)
{
	if(NULL != m_pStr) {
		delete []m_pStr;
		m_nLenth = 0;
	}

	int nLen = GetLen(Str);

	if(0 != nLen) {
		Copy(Str);
	}
	return *this;
}

char& CString::operator[](int nIdex)
{
	return m_pStr[nIdex];
}

bool CString::operator==(const char *pStr)
{
	int nLen = GetLen(pStr);

	if(NULL != pStr){
		for(int i = 0; i <= nLen;i++){
			if(pStr[i] != m_pStr[i]){
				return false;
			}
		}
	}
	return true;
}

bool CString::operator==(const CString &obj)
{
	int nLen = GetLen(obj.m_pStr);
	if(NULL != obj.m_pStr){
		for(int i = 0; i <= nLen;i++){
			if(obj.m_pStr[i] != m_pStr[i]){
				return false;
			}
		}
	}
	return true;
}

bool operator==(const char *pStr,const CString &obj)
{
	int nLen = obj.m_nLenth;
	if (NULL != obj.m_pStr) {
		for (int i = 0; i <= nLen;i++) {
			if (nLen != obj.m_nLenth) {
				return false;
			}
			if (pStr[i] != obj.m_pStr[i]) {
				return false;
			}
		}
	}
	return true;
}

ostream& operator<<(ostream &out,const CString &pStr)
{
	if (NULL != pStr.m_pStr) {
		out<<pStr.m_pStr;
	}

	return out;

}

istream& operator>>(istream &in,CString &pStr)
{
	char szBuf[255];

	in>>szBuf;
	if (NULL != pStr.m_pStr) {
		pStr.m_pStr = NULL;
		pStr.m_nLenth = 0;
	}
	pStr = szBuf;
	return in;
}