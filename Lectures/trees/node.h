#pragma once

template <class T1>
class Node {
    private:
    T1 _data;
    Node<T1>* _left;
    Node<T1>* _right;

    public:
    Node();
    void setData(T1);
    void setLeft(Node<T1>*);
    void setRight(Node<T1>*);

    T1 getData();
    Node<T1>* getLeft();
    Node<T1>* getRight();

};