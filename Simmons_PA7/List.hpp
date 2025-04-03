/******************************************************************************************
* Programmer: Tyler Simmons
* Course: Cpt S 122
* Date: 03/21/2025
* TA: Berkeley Conkling
* Assignment: PA7
******************************************************************************************/

#pragma once
#include "ctype.h"
#include "Node.hpp"
#include "Data.hpp"

template<class T>
class List
{
public:
    //core constructor
    List(Node<T>* newPtr = nullptr);
    //copy constructor
    List(const List<T>& newList);
    //copy assignment operator
    List<T>& operator=(const List<T>& rhs);
    //destructor
    ~List();
    //getters
    Node<T>* getHeadPtr() const;
    //setters
    void setHeadPtr(Node<T>* const newPtr);

    //member functions
    void insert(T newData);
    bool deleteList(Node<T>* pNode);
    //void print();

private:
    Node<T>* mpHead;
};

template<class T>
List<T>::List(Node<T>* newPtr)
{
    mpHead = newPtr;
}

template<class T>
List<T>::List(const List<T>& newList)
{
    mpHead = newList.mpHead;
}

template<class T>
List<T>& List<T>::operator=(const List& rhs)
{
    mpHead = rhs.mpHead;

    return *this;
}

template<class T>
List<T>::~List()
{
}

template<class T>
Node<T>* List<T>::getHeadPtr() const
{
    return mpHead;
}

template<class T>
void List<T>::setHeadPtr(Node<T>* const newPtr)
{
    mpHead = newPtr;
}

template<class T>
void List<T>::insert(T newData)
{
    Node<T>* pTemp = this->mpHead,
             *pMem = new Node<T>(newData, nullptr);

    if (mpHead == nullptr)
    {
        mpHead = pMem;
    }
    else
    {
        while (pTemp->getNextPtr() != nullptr)
        {
            pTemp = pTemp->getNextPtr();
        }

        pTemp->setNextPtr(pMem);
    }
}

template<class T>
bool List<T>::deleteList(Node<T>* pNode)
{
    bool deleteTest = false;

    if (pNode == nullptr)
    {
        mpHead = pNode;
        deleteTest = true;
        return deleteTest;
    }
    else
    {
        deleteList(pNode->getNextPtr());
    }
    delete pNode;

    return deleteTest;
}
