#ifndef __AVLNODE_H
#define __AVLNODE_H

template <typename T>
class Node
{
public:
    T value;
    int height;
    int balance;
    Node *left;
    Node *right;
    Node *parent;

    Node(T val)
    {
        this->value = val;
        this->left = nullptr;
        this->right = nullptr;
        this->parent = nullptr;
        balance = 0;
        height = 0;
    }

    Node(T val, Node<T> *p)
    {
        this->value = val;
        this->left = nullptr;
        this->right = nullptr;
        this->parent = p;
        balance = 0;
        height = 0;
    }

    ~Node()
    {
        this->value = 0;
        this->left = nullptr;
        this->right = nullptr;
        this->parent = nullptr;
    }
};
#endif