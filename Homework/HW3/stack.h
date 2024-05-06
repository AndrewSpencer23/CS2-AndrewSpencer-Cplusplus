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
        Node<T1>* tempNode = _head;
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

// add an element to the beginning of the stack, updating _head
template <class T1>
void Stack<T1>::push(T1 data)
{
    Node<T1>* newNode = new Node<T1>();
    if(empty()) {
        newNode->setData(data);
        _head = newNode;
        stackSize++;
    }
    else if(!empty()) {
        newNode->setData(data);
        newNode->setNext(_head);
        _head = newNode;
        stackSize++;
    }
    delete newNode;
}


// remove the first element from the list and return its data
// if the list is empty, print that out and return 0;
template <class T1>
T1 Stack<T1>::pop()
{
    if(empty()) {
        cout << "List is empty" << endl;
        return 0;
    }
    else {
        T1 data;
        data = _head->getData();
        _head = _head->getNext();
        stackSize--;
        return data;
    }
}
