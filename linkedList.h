#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include <iostream>
#include "node.h"

template <class T1, class T2>

class linkedList
{
private:
    node<T1, T2> *head;
    //node<T1, T2> *tail;
    int length;

public:
    linkedList()
    {
        length = 0;
        head = NULL;
        //tail = NULL;
    }

    node<T1, T2> *getHead()
    {
        return head;
    }

    int getLength()
    {
        return length;
    }

    void addNode(node<T1, T2> *n)
    {
        length++;
        if (head == NULL)
        {
            head = n;
        }
        else
        {
            n->setNext(head);
            head = n;
        }
    }

    void removeNode(T1 deleted)
    {

        node<T1, T2> *temp = head;
        if (head->getDefinition() == deleted)
        {
            head = head->getNext();
            delete temp;
            length -= 1;
        }

        else
        {
            for (int i = 0; i < length; i++)
            {
                if (temp->getNext()->getNext() == NULL && temp->getNext()->getCommand() == deleted)
                {
                    delete temp->getNext();
                    temp->setNext(NULL);
                    break;
                }
                else if (temp->getNext()->getCommand() == deleted)
                {
                    node<T1, T2> *temp2 = temp->getNext();
                    temp->setNext(temp->getNext()->getNext());
                    delete temp2;
                    break;
                }
                temp = temp->getNext();
            }
        }
    }
    void deleteList(node<T1, T2> *temp)
    {
        if (temp->getNext() != NULL)
            deleteList(temp->getNext());
        //std::cout << "Deleted: " << temp->getCommand();
        delete temp;
    }
};

#endif