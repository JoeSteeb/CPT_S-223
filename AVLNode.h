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

    Node(T val, int h)
    {
        this->value = val;
        this->left = nullptr;
        this->right = nullptr;
        this->parent = nullptr;
        height = h;
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