#include <iostream>
#include "AVLNode.h"
#include "AVLTree.h"

int main()
{
    //std::cout << "Hello World";
    BST<int> *bst = new BST<int>();
    bst->add(11);
    bst->add(10);
    bst->add(6);
    //bst->add(10);
    //bst->add(-11);
    bst->add(100);
    bst->add(200);
    bst->add(300);
    bst->print();
    std::cout << "\n height: " << bst->height();
    bst->rightRotate(bst->_root);
    std::cout << "\n height: " << bst->height();
    bst->rightRotate(bst->_root);
    bst->leftRotate(bst->_root);
    std::cout << '\n';
    std::cout << '\n';
    bst->print();
    cout << endl;
}