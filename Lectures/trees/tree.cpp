#include "tree.h"

template <class T1>
void Tree<T1>::insert(T1 data) {
    _root = insertNode(_root, data);
}

template <class T1>
Node<T1>* Tree<T1>::insertNode(Node<T1>* root, T1 data) {
    if(root = nullptr) {
        Node<T1>* newNode = new Node<T1>();
        sewNode->setData(data);
        return newNode;
    }

    if(data < root->getData()) {
        root->setLeft(insertNode(root->getLeft(), data));
    }
    
    else if(data > root->getData()) {
        root->setRight(insertNode(root->getRight(), data));
    }
    return root;
}