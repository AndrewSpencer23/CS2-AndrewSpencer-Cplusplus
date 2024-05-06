#pragma once
#include "node.h"
#include <iostream>

using namespace std;

template <class T1>
class Stack
{
    private:
        Node<T1> *_head;
        size_t stackSize;

    public:
        Stack();
        ~Stack();

        bool empty();
        size_t size();

        void push(T1);
        T1 pop();

        bool operator==(const Stack<T1>&);
        // Have to declare a template for friend functions using a different template variable
        template <class T2>
        friend ostream &operator<<(ostream &, const Stack<T2> &);
};

// set to nullptr and initialize listSize
template <class T1>
Stack<T1>::Stack()
{
    _head = nullptr;
    stackSize = 0;
}

// iteratively delete the list starting at _head
template <class T1>
Stack<T1>::~Stack()
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
bool Stack<T1>::empty()
{
    if(stackSize == 0 && _head == nullptr) {
        return true;
    }
    else {
        return false;
    }
}

// return number of elements in list
template <class T1>
size_t Stack<T1>::size()
{
    return stackSize;
}

// add an element to the beginning of the list, updating _head
template <class T1>
void Stack<T1>::push(T1 data)
{
    Node<T1>* newNode = new Node<T1>();
    if(_head == nullptr) {
        _head = newNode;
    }
    else {
        _head->setPrev(newNode);
        newNode->setNext(_head);
        _head = newNode;
        _head->setData(data);
    }
    listSize++;
}


// remove the first element from the list and return its data
// if the list is empty, print that out and return 0;
template <class T1>
T1 Stack<T1>::pop()
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


// overloading <<, should return a space separated stream of all of the elements
template <class T1>
ostream &operator<<(ostream &os, const Stack<T1> &stack)
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
bool Stack<T1>::operator==(const Stack<T1>& rhs)
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