#pragma once
#include "node.h"
#include <iostream>

using namespace std;

template <class T1>
class List
{
    private:
        Node<T1> *_head;
        Node<T1> *_tail;
        size_t listSize;

    public:
        List();
        ~List();

        bool empty();
        size_t size();

        void push_front(T1);
        T1 pop_front();
        T1 front();
        void push_back(T1);
        T1 pop_back();
        T1 back();

        bool operator==(const List<T1>&);
        // Have to declare a template for friend functions using a different template variable
        template <class T2>
        friend ostream &operator<<(ostream &, const List<T2> &);
};

// set to nullptr and initialize listSize
template <class T1>
List<T1>::List()
{
    _head = nullptr;
    _tail = nullptr;
    listSize = 0;
}

// iteratively delete the list starting at _head
template <class T1>
List<T1>::~List()
{
    while(_head != nullptr) {
        Node<T1>* tempNode = new Node<T1>();
        tempNode = _head;
        _head = _head->getNext();
        delete tempNode;
    }
}

// return true if the list is empty, false otherwise.
// Do not just check listSize, should actually check _head and _tail
template <class T1>
bool List<T1>::empty()
{
    if(listSize == 0 && _head == nullptr && _tail == nullptr) {
        return true;
    }
    else {
        return false;
    }
}

// return number of elements in list
template <class T1>
size_t List<T1>::size()
{
    return listSize;
}

// add an element to the beginning of the list, updating _head
template <class T1>
void List<T1>::push_front(T1 data)
{
    Node<T1>* newNode = new Node<T1>();
    if(_head == nullptr) {
        _head = newNode;
        _tail = newNode;
    }
    else {
        newNode->setNext(_head);
        _head->setPrev(newNode);
        _head = newNode;
    }
    listSize++;
}

// return the first element in the list.
// if the list is empty, print that out and return 0
template <class T1>
T1 List<T1>::front()
{
    if(_head == nullptr) {
        cout << "The list is empty" << endl;
        return 0;
    }
    else {
        return _head->getData();
    }
}

// remove the first element from the list and return its data
// if the list is empty, print that out and return 0;
template <class T1>
T1 List<T1>::pop_front()
{
    if(_head == nullptr) {
        cout << "List is empty" << endl;
        return 0;
    }
    else {
        T1 data;
        data = _head->getData();
        _head = _head->getNext();
        _head->setPrev(nullptr);
        listSize--;
        return data;
    }
}

// add an element to the end of hte list, updating _tail
template <class T1>
void List<T1>::push_back(T1 data)
{
    Node<T1>* newNode = new Node<T1>();
    if(_tail == nullptr) {
        _head = newNode;
        _tail = newNode;
    }
    else {
        newNode->setPrev(_tail);
        newNode->setNext(nullptr);
        _tail->setNext(newNode);
        _tail = newNode;
    }
    listSize++;
}

// return the last element in the list.
// if the list is empty, print that out and return 0
template <class T1>
T1 List<T1>::back()
{
}

// remove the last element from the list and return its data
// if the list is empty, print that out and return 0;
template <class T1>
T1 List<T1>::pop_back()
{
}

// overloading <<, should return a space separated stream of all of the elements
template <class T1>
ostream &operator<<(ostream &os, const List<T1> &list)
{
    Node<T1>* tempNode = new Node<T1>();
    tempNode = list._head;
    
    while(tempNode->getNext() != nullptr) {
        os << tempNode->getData() << " ";
        tempNode = tempNode->getNext();
    }

    os << tempNode->getData();
    return os;
}

// should iterate through each list to check that they are exactly the same
template <class T1>
bool List<T1>::operator==(const List<T1>& rhs)
{
    if (listSize != rhs.listSize) {
        return false;
    }

    Node<T1>* curNode1 = new Node<T1>();
    Node<T1>* curNode2 = new Node<T1>();
    curNode1 = _head;
    curNode2 = rhs._head;

    while(curNode1 != nullptr && curNode2 != nullptr) {
        if(curNode1->getData() == curNode2->getData()) {
            return true;
        }
        else{
            curNode1 = curNode1->getNext();
            curNode2 = curNode2->getNext();
        }
    }

    return false;
}