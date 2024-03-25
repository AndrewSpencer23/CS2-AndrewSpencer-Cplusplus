#pragma once;
#include "node.h"

template <class T1>
class Tree {
    private:
    Node<T1>* _root;
    Node<T1>* insertNode(Node<T1>*, T1);

    public:
    void insert(T1);
};