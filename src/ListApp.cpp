#include "StdAfx.h"
#include "String.h"
#include "List.h"

int main(int argc, char* argv[])
{

	CList obj;

	obj.CreateList();

	cout<<obj;

	cout<<obj.FindNode("123")<<endl;

	obj.ClearList();
	return 0;

}
