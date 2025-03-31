/******************************************************************************************
* Programmer: Tyler Simmons
* Course: Cpt S 122
* Date: 03/21/2025
* TA: Berkeley Conkling
* Assignment: PA6 with extra credit
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
    void insert(Node<T>* const pNode, T newData);
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
    Node<T>* pTemp = mpHead,
             pPrev = mpHead;

    while (mpHead != nullptr)
    {
        while (pTemp->getNextPtr() != nullptr)
        {
            pPrev = pTemp;
            pTemp = pTemp->getNextPtr();
        }
        delete pTemp;
        pPrev.setNextPtr(nullptr);
        pTemp = mpHead;
        pPrev = mpHead;
    }
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
void List<T>::insert(Node<T>* const pNode, T newData)
{
    Node<T>* pTemp = pNode,
        pMem = new Node(newData, nullptr);

    if (mpHead == nullptr)
    {
        mpHead = new Node<T>(newData, nullptr);
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