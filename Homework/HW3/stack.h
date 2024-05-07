#pragma once
#include "node.h"
#include <iostream>

using namespace std;

template <class T1>
class Stack
{
    private:
        Node<T1> *_top;
        size_t stackSize;

    public:
        Stack();
        ~Stack();

        bool empty();
        size_t size();

        void push(T1);
        T1 pop();
};

// set to nullptr and initialize stackSize
template <class T1>
Stack<T1>::Stack()
{
    _top = nullptr;
    stackSize = 0;
}

// iteratively delete the stack starting at _top
template <class T1>
Stack<T1>::~Stack()
{
    while(_top != nullptr) {
        Node<T1>* tempNode = _top;
        _top = _top->getNext();
        delete tempNode;
    }
}

// return true if the stack is empty, false otherwise.
// Do not just check stackSize, should actually check _top
template <class T1>
bool Stack<T1>::empty()
{
    if(stackSize == 0 && _top == nullptr) {
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
    newNode->setData(data);
    newNode->setNext(_top);
    _top = newNode;
    stackSize++;
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
        Node<T1>* tempNode;
        tempNode = _top;
        data = _top->getData();
        _top = _top->getNext();
        delete tempNode;
        stackSize--;
        return data;
    }
}
