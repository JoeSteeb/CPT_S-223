#ifndef NODE_H
#define NODE_H

template <class T1, class T2>
class node
{
private:
    T1 command;
    T2 definition;
    node *next;

public:
    node(T1 Command, T2 Definition)
    {
        command = Command;
        definition = Definition;
    }
    T1 getCommand()
    {
        return command;
    }

    T2 getDefinition()
    {
        return definition;
    }

    void setNext(node *Next)
    {
        next = Next;
    }

    node *getNext()
    {
        return next;
    }
};

#endif