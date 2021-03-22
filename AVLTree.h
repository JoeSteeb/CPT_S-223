#ifndef __BST_H
#define __BST_H

#include <iostream>
#include <sstream>
#include <vector>
#include <limits>
#include "AVLNode.h"

using namespace std;

template <typename T>
class AVLTree
{
protected:
    Node<T> *_root; // Root of the tree nodes

    /* Add new T val to the tree */
    void leftRotate(Node<T> *root)
    {

        Node<T> *temp = root->right->left;
        if (root->parent != nullptr)
        {
            if (root->parent->right == root)
            {
                root->parent->right = root->right;
                root->right->parent = root->parent;
            }
            else
            {
                root->parent->left = root->right;
                root->right->parent = root->parent;
            }
        }
        else if (root->right != nullptr)
        {
            this->_root = root->right;
            this->_root->parent = nullptr;
        }
        else
            cout << "error";

        root->right->left = root;
        root->parent = root->right;

        root->right = temp;

        if (temp != nullptr)
            temp->parent = root;

        updateHeight();
    }

    void rightRotate(Node<T> *root)
    {
        Node<T> *temp = root->left->right;
        if (root->parent != nullptr)
        {
            if (root->parent->right == root)
            {
                root->parent->right = root->left;
                root->left->parent = root->parent;
            }
            else
            {
                root->parent->left = root->left;
                root->left->parent = root->parent;
            }
        }
        else if (root->left != nullptr)
        {
            this->_root = root->left;
            this->_root->parent = nullptr;
        }
        else
            cout << "error";

        root->left->right = root;
        root->parent = root->left;

        root->left = temp;

        if (temp != nullptr)
            temp->parent = root;

        updateHeight();
    }

    void updateHeightHelper(Node<T> *root)
    {
        if (root->right != nullptr)
        {
            updateHeightHelper(root->right);
        }
        if (root->left != nullptr)
        {
            updateHeightHelper(root->left);
        }
        root->height = heightHelper(root);
    }

    void updateHeight()
    {
        updateHeightHelper(this->_root);
    }

    int getBalance(Node<T> *root)
    {
        int tempHL;
        int tempHR;
        if (root == nullptr)
            return 0;
        if (root->left == nullptr)
            tempHL = -1;
        else
            tempHL = root->left->height;
        if (root->right == nullptr)
            tempHR = -1;
        else
            tempHR = root->right->height;

        return tempHL - tempHR;
    }

    void addHelper(Node<T> *root, T val)
    {
        bool updateH;
        if (!root->left && !root->right)
            updateH = true;
        if (root->value > val)
        {
            if (!root->left)
            {
                root->left = new Node<T>(val, root);
            }
            else
            {
                addHelper(root->left, val);
            }
        }
        else
        {
            if (!root->right)
            {
                root->right = new Node<T>(val, root);
            }
            else
            {
                addHelper(root->right, val);
            }
        }
        if (updateH)
            updateHeight();

        //Balancing tree

        int balance = getBalance(root);

        if (balance > 1)
        {
            if (getBalance(root->left) < 0)
            {
                leftRotate(root->left);
                rightRotate(root);
            }
            else
                rightRotate(root);
        }

        else if (balance < -1)
        {
            if (getBalance(root->right) > 0)
            {
                rightRotate(root->right);
                leftRotate(root);
            }
            else
                leftRotate(root);
        }
    }

    /* Return number of nodes in tree */
    int nodesCountHelper(Node<T> *root)
    {
        if (!root)
        {
            return 0;
        }
        else
        {
            return 1 + nodesCountHelper(root->left) + nodesCountHelper(root->right);
        }
    }

    /* Return height of tree (root == nullptr -> 0) */
    int heightHelper(Node<T> *root)
    {
        if (!root)
        {
            return -1;
        }
        else
        {
            return 1 + max(heightHelper(root->left), heightHelper(root->right));
        }
    }

    void printInOrderHelper(Node<T> *root)
    {
        if (!root)
            return;
        printInOrderHelper(root->left);
        cout << root->value << " height: " << root->height << ' ';
        printInOrderHelper(root->right);
    }

    bool validateHelper(Node<T> *root)
    {
        int balance = getBalance(root);

        if (balance < -1 || balance > 1)
            return false;
        else
        {
            if (root->left != nullptr && root->right)
            {
                return min(validateHelper(root->left), validateHelper(root->right));
            }
        }

        return true;
    }

    /********************************* PUBLIC API *****************************/
public:
    AVLTree() : _root(nullptr) {} // Basic initialization constructor

    /**
	 * Destructor - Needs to free *all* nodes in the tree
	 * TODO: Implement Destructor
	 */

    void treeDelete(Node<T> *dNode)
    {
        if (dNode->left != nullptr)
            treeDelete(dNode->left);

        if (dNode->right != nullptr)
            treeDelete(dNode->right);

        delete dNode;
    }

    ~AVLTree()
    {
        //cout << "TODO: Implement Destructor" << endl;
        if (this->_root != nullptr)
            treeDelete(this->_root);
    }

    /* Public API */
    void insert(T val)
    {
        if (this->_root)
        {
            this->addHelper(this->_root, val);
        }
        else
        {
            this->_root = new Node<T>(val);
        }
    }

    /**
	 * Print the nodes level by level, starting from the root
	 * TODO: Implement printLevelOrder
	 */

    int nodesCount()
    {
        return nodesCountHelper(this->_root);
    }

    int height()
    {
        return heightHelper(this->_root);
    }

    void print()
    {
        printInOrderHelper(this->_root);
    }

    bool containsN(Node<T> *pNode, T value)
    {
        if (pNode == NULL)
            return false;
        else if (pNode->value > value)
            return containsN(pNode->left, value);
        else if (pNode->value < value)
            return containsN(pNode->right, value);
        else
            return true;
        //return true;
    }

    bool contains(T value)
    {
        //cout << "TODO: Implement contains" << endl;
        //return numeric_limits<T>::min();
        return containsN(this->_root, value);
    }

    bool validate()
    {
        return validateHelper(_root);
    }
};

#endif
