#ifndef __AVLNODE_H
#define __AVLNODE_H

template <typename T>
class Node
{
public:
    T value;
    int height;
    Node *left;
    Node *right;
    Node *parent;

    Node(T val)
    {
        this->value = val;
        this->left = nullptr;
        this->right = nullptr;
        this->parent = nullptr;
        height = 0;
    }

    Node(T val, Node<T> *p)
    {
        this->value = val;
        this->left = nullptr;
        this->right = nullptr;
        this->parent = p;
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