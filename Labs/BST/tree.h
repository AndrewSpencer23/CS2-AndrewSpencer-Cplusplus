#pragma once
#include "node.h"
#include <iostream>

using namespace std;

template <class T1>
class BST
{
private:
    Node<T1> *_root;

    Node<T1> *insertNode(Node<T1> *, T1);
    void inOrderPrint(Node<T1> *);
    Node<T1> *searchData(Node<T1> *, T1);
    Node<T1> *removeData(Node<T1> *, T1);
    Node<T1> *minVal(Node<T1> *);
    void destroyTree(Node<T1>*);

public:
    BST();
    ~BST();
    void insert(T1);
    void inOrder();
    bool search(T1);
    void remove(T1);
};

template <class T1>
BST<T1>::BST() : _root(nullptr) {}

template <class T1>
BST<T1>::~BST()
{
    destroyTree(_root);
}

template <class T1>
void BST<T1>::destroyTree(Node<T1>* root)
{
    if(root == nullptr) {
        return;
    }
    destroyTree(root->getLeft());
    destroyTree(root->getRight());
    delete root;
}

template <class T1>
Node<T1> *BST<T1>::insertNode(Node<T1> *root, T1 data)
{
    if(root == nullptr) {
        Node<T1>* addedNode = new Node<T1>();
        addedNode->setData(data);
        return addedNode;
    }
    if(data < root->getData()) {
        root->setLeft(insertNode(root->getLeft(), data));
    }
    else if(data > root->getData()) {
        root->setRight(insertNode(root->getRight(), data));
    }
    return root;
}

template <class T1>
void BST<T1>::insert(T1 data)
{
    _root = insertNode(_root, data);
}

template <class T1>
void BST<T1>::inOrderPrint(Node<T1> *root)
{
    if(root == nullptr) {
        return;
    }
    inOrderPrint(root->getLeft());
    cout << root->getData() << " ";
    inOrderPrint(root->getRight());
}

template <class T1>
void BST<T1>::inOrder()
{
    inOrderPrint(_root);
    cout << endl;
}

template <class T1>
Node<T1> *BST<T1>::searchData(Node<T1> *root, T1 data)
{
    if(root == nullptr || root->getData() == data) {
        return root;
    }
    if(data < root->getData()) {
        return searchData(root->getLeft(), data);
    }
    return searchData(root->getRight(), data);
}

template <class T1>
bool BST<T1>::search(T1 data)
{
    Node<T1>* searchNode;
    searchNode = searchData(_root, data);
    return searchNode != nullptr;
}

template <class T1>
Node<T1> *BST<T1>::removeData(Node<T1> *root, T1 data)
{
    if(root == nullptr) {
        return root;
    }
    if(data < root->getData()) {
        root->setLeft(removeData(root->getLeft(), data));
    }
    else if(data > root->getData()) {
        root->setRight(removeData(root->getRight(), data));
    }
    else {
        if(root->getLeft() == nullptr) {
            Node<T1>* tempNode = root->getRight();
            delete root;
            return tempNode;
        }
        else if(root->getRight() == nullptr) {
            Node<T1>* tempNode = root->getLeft();
            delete root;
            return tempNode;
        }
        Node<T1>* tempNode = minVal(root->getRight());
        root->setData(tempNode->getData());
        root->setRight(removeData(root->getRight(), tempNode->getData()));
    }
    return root;
}

template <class T1>
Node<T1> *BST<T1>::minVal(Node<T1> *root)
{
    Node<T1>* currentNode = root;
    while(currentNode->getLeft() != nullptr && currentNode != nullptr) {
        currentNode = currentNode->getLeft();
    }
    return currentNode;
}

template <class T1>
void BST<T1>::remove(T1 data)
{
    _root = removeData(_root, data);
}