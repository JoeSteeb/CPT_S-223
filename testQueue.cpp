#include "testQueue.h"
#include "queue.h"
#include <iostream>

void test::dequeue()
{

}
void test::enqueue()
{
    /*
    Test ID:
    Unit:
    Description:
    data:
    Precondition:
    Postcondition:
    result:
    Actual result:
    returnedStatus:
    */
    //steeb

    //case1: add and check
    std::cout << "testing enqueue: " << '\n';
    queue testq;
    for(int i = 0; i < testq.getCapacity(); i++)
    {
        testq.enqueue(1);
    }
    for(int i = 0; i < testq.getCapacity(); i++)
    {
        int temp = testq.peek();
        std::cout << temp;
        if(temp != 1)
        {
            std::cout << "enqueue test failed, value enqueued did not match value peeked" << '\n';
            break;
        }
        testq.dequeue();
    }

    //case2: overflow prevention
    testq.setCapacity(0);
    std::cout << "enqueue test failed, program should overflow and terminate:" << '\n';
    testq.enqueue(1);   

}
void test::peek()
{
    //steeb
    std::cout << "testing peek:" << '\n';
    queue testq;
    testq.enqueue(1);
    if(testq.peek() != 1)
        std::cout << "peek test failed, peeked value does not match input" << '\n';
}
void test::size()
{

}
void test::isEmpty()
{
    /*
    Test ID:
    Unit:
    Description:
    data:
    Precondition:
    Postcondition:
    result:
    Actual result:
    returnedStatus:
    */
    //steeb
    std::cout << "testing isEmpty:" << '\n';
    queue testq;
    if(testq.isEmpty())
        std::cout << "isEmpty test failed, program faild to recognize newly created queue" << '\n';
}
void test::isFull()
{
    /*
    Test ID:
    Unit:
    Description:
    data:
    Precondition:
    Postcondition:
    result:
    Actual result:
    returnedStatus:
    */

}