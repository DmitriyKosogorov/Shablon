#pragma once
#ifndef _LIST_H
#define _LIST_H

using namespace std;

class LineListException{};

template <class T> class LineListElem
{
private:
    T data;
    LineListElem* next;
public:
    LineListElem(const T& adata, LineListElem* anext);
    const T& getData() const;
    LineListElem* getNext();
    template <class T1> friend class LineList;
};

template <class T> class LineList
{
private:
    LineListElem<T>* start;// Начало списка
    LineListElem<T>* finish;
    LineList(const LineList& list);
    LineList& operator =(const LineList& list);
	int size = 0;
public:
    LineList();
    ~LineList();
    LineListElem<T>* getStart();
	LineListElem<T>* getFinish();
    T operator [](int index);
    void deleteFirst();
    void deleteAfter(LineListElem<T>* ptr);
    void insertFirst(const T& data);
    void insertAfter(LineListElem<T>* ptr, const T& data);
	int getSize();
    template <class T1> friend ostream& operator <<(ostream& out, LineList<T1>& list);
};



template<class T> void LineList<T>::deleteFirst()
{
	if (start)
	{
		LineListElem<T>* temp = start->next;
		delete start;
		start = temp;
		finish->next = start;
		size = size - 1;
	}
	else throw LineListException();
}
template<class T> LineList<T>::LineList()
{
	start = 0;
	finish = 0;
}
template<class T> LineList<T>::~LineList()
{
	for (int i = 0; i < size;i++) deleteFirst();
	size = 0;
}
template<class T> LineListElem<T>* LineList<T>::getStart()
{
	return(start);
}
template<class T> LineListElem<T>* LineList<T>::getFinish()
{
	return(finish);
}
template<class T> void LineList<T>::insertFirst(const T& data)
{
	LineListElem<T>* second = start;
	start = new LineListElem<T>(data, second);
	if (size == 0)
		finish = start;
	else
		finish->next = start;
	size = size + 1;
}
template<class T> void LineList<T>::deleteAfter(LineListElem<T>* ptr)
{
	if (ptr && ptr->next)
	{
		LineListElem<T>* temp = ptr->next;
		if (temp == finish)
			finish = ptr;
		if (temp == start)
			start = ptr;
		ptr->next = ptr->next->next;
		delete temp;
		size = size - 1;
	}
	else
		throw LineListException();
}
template<class T> void LineList<T>::insertAfter(LineListElem<T>* ptr, const T& data)
{
	if (ptr)
	{
		LineListElem<T>* temp = ptr->next;
		ptr->next = new LineListElem<T>(data, temp);
		if (ptr == finish)
			finish = ptr->next;
		finish->next = start;
		size = size + 1;
	}
}
template<class T> int LineList<T>::getSize()
{
	return(size);
}
template<class T> ostream& operator<<(ostream& out, LineList<T>& list)
{
	LineListElem<T>* ptr = list.start;
	if (!ptr)
		out << "EMPTY ";
	else while (ptr)
	{
		out << ptr->getData() << ' ';
		ptr = ptr->getNext();
	}
	return out;
}
template<class T> T LineList<T>::operator [](int index)
{
	LineListElem<T>* ptr = start;
	if(index>=size)
		throw LineListException();
	else
	{
		for (int i = 0; i < index; i++)
		{
			ptr = ptr->getNext();
		}
		return ptr->getData();
	}
}
template<class T> LineListElem<T>::LineListElem(const T& adata, LineListElem<T>* anext)
{
	data = adata;
	next = anext;
}
template<class T> const T& LineListElem<T>::getData() const
{
    return data;
}
template<class T> LineListElem<T>* LineListElem<T>::getNext()
{
	return next;
}
#endif

