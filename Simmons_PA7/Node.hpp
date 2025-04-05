/******************************************************************************************
* Programmer: Tyler Simmons
* Course: Cpt S 122
* Date: 4/4/2025
* TA: Berkeley Conkling
* Assignment: PA7
******************************************************************************************/
#pragma once
#include <iostream>
using std::string;
#include "Data.hpp"

template <class T>
class Node
{
public:
	//core constructor
	Node(T& newData, Node<T>* newPtr = nullptr);
	//copy constructor
	Node(const Node<T>& newNode);
	//copy assignment operator
	Node<T>& operator=(const Node<T>& rhs);
	//destructor
	~Node();
	//getters
	T getData();
	Node<T>* getNextPtr() const;
	//setters
	void setData(const T newData);
	void setNextPtr(Node<T>* const newPtr);

private:
	T mData;
	Node<T>* mpNext;
};

template<class T>
Node<T>::Node(T& newData, Node* newPtr)
{
	mData = newData;
	mpNext = newPtr;
}

template<class T>
Node<T>::Node(const Node<T>& newNode)
{
	mData = newNode.mData;
	mpNext = newNode.mpNext;
}

template<class T>
Node<T>& Node<T>::operator=(const Node<T>& rhs)
{
	mData.setRecordNo(rhs.mData.getRecordNo());
	mData.setIDNo(rhs.mData.getIDNo());
	mData.setName(rhs.mData.getName());
	mData.setEmail(rhs.mData.getEmail());
	mData.setUnits(rhs.mData.getUnits());
	mData.setProgram(rhs.mData.getProgram());
	mData.setNumAbsences(rhs.mData.getNumAbsences());
	mData.setAbsenceDates(rhs.mData.getAbsenceDates());

	return *this;
}

template<class T>
Node<T>::~Node()
{
}

template<class T>
T Node<T>::getData()
{
	return mData;
}

template<class T>
Node<T>* Node<T>::getNextPtr() const
{
	return mpNext;
}

template<class T>
void Node<T>::setData(const T newData)
{
	mData.setRecordNo(newData.getRecordNo());
	mData.setIDNo(newData.getIDNo());
	mData.setName(newData.getName());
	mData.setEmail(newData.getEmail());
	mData.setUnits(newData.getUnits());
	mData.setProgram(newData.getProgram());
	mData.setLevel(newData.getLevel());
	mData.setNumAbsences(newData.getNumAbsences());
	mData.setAbsenceDates(newData.getAbsenceDates());
}

template<class T>
void Node<T>::setNextPtr(Node<T>* const newPtr)
{
	mpNext = newPtr;
}