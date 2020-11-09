#include<iostream>
#include "LineList.h"
using namespace std;
int main(void)
{
	/*LineList<int> list;// Указываем, список какого типа
	cout<<"Starting: "<<list<<endl;
	list.insertFirst(10);
	LineListElem<int>* ptr = list.getStart();
	list.insertAfter(ptr, 15);
	list.insertAfter(ptr->getNext(), 12);
	list.insertFirst(7);
	//cout<<"Step1: "<<list<<endl;
	int n = list.getSize();
	for (int i = 0; i < n; i++)
		cout << list[i]<<endl;
	cout <<endl<< list.getFinish()->getData();
	*/
	int i, n = 50;
	LineList<int> list;// Указываем, список какого типа
	list.insertFirst(1);	
	LineListElem<int>* ptr = list.getStart();
	for (i = 1; i < n - 1; i++)
	{
		list.insertAfter(ptr, i + 1);
		ptr = ptr->getNext();
	}
	ptr = list.getStart();
	while (list.getSize() > 1)
	{
		ptr = ptr->getNext()->getNext();
		list.deleteAfter(ptr);
	}
	cout << "";
	cout << list.getFinish()->getData();
	return 0;
}
