#ifndef __BST_H
#define __BST_H

#include <iostream>
#include <sstream>
#include <vector>
#include <limits>
using namespace std;

/*
 *  Data structure for a single tree node
 */
template <typename T>
struct Node
{
public:
    T value;
    Node *left;
    Node *right;

    Node(T val)
    {
        this->value = val;
        this->left = nullptr;
        this->right = nullptr;
    }

    ~Node()
    {
        this->value = 0;
        this->left = nullptr;
        this->right = nullptr;
    }
};

/*
 * Binary Search Tree (BST) class implementation
 */
template <typename T>
class BST
{

protected:
    Node<T> *_root; // Root of the tree nodes

    /* Add new T val to the tree */
    void addHelper(Node<T> *root, T val)
    {
        if (root->value > val)
        {
            if (!root->left)
            {
                root->left = new Node<T>(val);
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
                root->right = new Node<T>(val);
            }
            else
            {
                addHelper(root->right, val);
            }
        }
    }

    /* Print tree out in inorder (A + B) */
    void printInOrderHelper(Node<T> *root)
    {
        if (!root)
            return;
        printInOrderHelper(root->left);
        cout << root->value << ' ';
        printInOrderHelper(root->right);
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

    /* Delete a given <T> value from tree */
    bool deleteValueHelper(Node<T> *parent, Node<T> *current, T value)
    {
        if (!current)
            return false;
        if (current->value == value)
        {
            if (current->left == nullptr || current->right == nullptr)
            {
                Node<T> *temp = current->left;
                if (current->right)
                    temp = current->right;
                if (parent)
                {
                    if (parent->left == current)
                    {
                        parent->left = temp;
                    }
                    else
                    {
                        parent->right = temp;
                    }
                }
                else
                {
                    this->_root = temp;
                }
            }
            else
            {
                Node<T> *validSubs = current->right;
                while (validSubs->left)
                {
                    validSubs = validSubs->left;
                }
                T temp = current->value;
                current->value = validSubs->value;
                validSubs->value = temp;
                return deleteValueHelper(current, current->right, temp);
            }
            delete current;
            return true;
        }
        return deleteValueHelper(current, current->left, value) ||
               deleteValueHelper(current, current->right, value);
    }

    /********************************* PUBLIC API *****************************/
public:
    BST() : _root(nullptr) {} // Basic initialization constructor

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

    ~BST()
    {
        cout << "TODO: Implement Destructor" << endl;
        if (this->_root != nullptr)
            treeDelete(this->_root);
    }

    /* Public API */
    void add(T val)
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

    void print()
    {
        printInOrderHelper(this->_root);
    }

    /**
	 * Print the nodes level by level, starting from the root
	 * TODO: Implement printLevelOrder
	 */

    void printLevelOrder()
    {
        int tHeight = this->height() + 1;
        std::vector<Node<T> *> levels[tHeight];
        levels[0].push_back(this->_root);

        for (int i = 1; i < tHeight; i++)
        {
            for (int j = 0; j < (int)levels[i - 1].size(); j++)
            {
                if (levels[i - 1][j]->left != nullptr)
                    levels[i].push_back(levels[i - 1][j]->left);
                if (levels[i - 1][j]->right != nullptr)
                    levels[i].push_back(levels[i - 1][j]->right);
            }
        }

        for (int i = 0; i < tHeight; i++)
        {
            for (int j = 0; j < (int)levels[i].size(); j++)
            {
                std::cout << levels[i][j]->value << " ";
            }
            std::cout << '\n';
        }
    }

    int nodesCount()
    {
        return nodesCountHelper(this->_root);
    }

    int height()
    {
        return heightHelper(this->_root);
    }

    /**
	 * Print the maximum path in this tree
	 * TODO: Implement printMaxPath
	 */
    void printMaxPath()
    {
        cout << "TODO: Implement printMaxPath" << endl;
    }

    bool deleteValue(T value)
    {
        return this->deleteValueHelper(nullptr, this->_root, value);
    }

    /**
	 * Find if the BST contains the value
	 * TODO: Implement contains
	 */

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
};

#endif
