#include <iostream>
#include <algorithm>
#include <time.h>
#include <stdlib.h>
#include <array>
#include "AVLNode.h"
#include "AVLTree.h"

using namespace std;

int main()
{
    //std::cout << "Hello World";
    AVLTree<int> treeAscending;
    AVLTree<int> treeDescending;
    AVLTree<int> treeRandom;

    array<int, 50> ascending;
    array<int, 50> descending;
    array<int, 50> Random;

    for (int i = 1; i <= 100; i += 2)
    {
        ascending[i / 2] = i;
        descending[i / 2] = i;
        Random[i / 2] = i;
    }

    reverse(descending.begin(), descending.end());

    srand(time(NULL));
    for (int i = 0; i < 50; i++)
    {
        int index1 = rand() % 49;
        int index2 = rand() % 49;
        int temp = Random[index1];

        Random[index1] = Random[index2];
        Random[index2] = temp;
    }

    int s1 = 0;
    for (int &element : ascending)
    {
        //cout << element << ' ';
        treeAscending.insert(element);
        s1 += element;
    }

    //cout << '\n';

    for (int &element : descending)
    {
        cout << element << ' ';
        treeDescending.insert(element);
    }

    cout << '\n';

    int s2 = 0;
    for (int &element : Random)
    {
        cout << element << ' ';
        treeRandom.insert(element);
        s2 += element;
    }

    cout << '\n';

    cout << "ascending tree valid? " << treeAscending.validate() << '\n';
    cout << "descending tree valid? " << treeDescending.validate() << '\n';
    cout << "random tree valid? " << treeRandom.validate() << "\n\n";

    bool correct = true;
    for (int i = 0; i < 100; i++)
    {
        if (i % 2 == 0 && (treeAscending.contains(i) || treeDescending.contains(i) || treeRandom.contains(i)))
        {
            correct = false;
        }

        if (i % 2 != 0 && (!treeAscending.contains(i) || !treeDescending.contains(i) || !treeRandom.contains(i)))
        {
            correct = false;
        }
    }
    if (correct)
        cout << "My AVL implementation is correct" << '\n';
    else
        cout << "My AVL tree implementation is wrong" << '\n';

    cout << "minimum expected height of trees: 5 or 6" << '\n';
    cout << "height of my ascending tree " << treeAscending.height() << '\n';
    cout << "height of my descending tree " << treeDescending.height() << '\n';
    cout << "height of my random tree " << treeRandom.height() << "\n\n";

    cout << "ascending numSum: " << s1;
    cout << "random numSum: " << s2;
}