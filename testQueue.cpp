#include "testQueue.h"
#include "queue.h"
#include <iostream>

void test::dequeue()
{
    /*
    Test ID:
    Unit:
    Description:
    data size:
    Precondition:
    Postcondition:
    expected result:
    Actual result:
    returnedStatus:
    */


}
void test::enqueue()
{
    /*
    Test ID: enque push and check
    Unit: test::enqueue()
    Description: fills up a queue with 1's and checks all elements
    data size: maximum size of queue
    Precondition: peek and dequeue functioning
    Postcondition: enqueue is full 
    expected result: enque is full with 1's
    Actual result: initially the resultent queue contained the size of the queue in each element.
    The function was fixed and is now working.
    Status: passed
    */

    //steeb
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

    /*
    Test ID: Overflow Test
    Unit: test::enqueue()
    Description: makes capacity zero and tries to add an element
    data size: 1
    Precondition: queue capacity set to zero, and element attempted to add
    Postcondition: no elements added
    expected result: no elements added
    Actual result: no elements added
    returnedStatus: passed
    */
    testq.setCapacity(0);
    std::cout << "enqueue test failed, program should overflow and terminate:" << '\n';
    testq.enqueue(1);   

}
void test::peek()
{
    /*
    Test ID: single element peek check
    Unit: test::peek()
    Description: checks if peek returns the only element in a 1 element size queue
    Test dataSize: 1
    Precondition: enque functioning and 1 is added to the queue
    Postcondition: 1 is peeked
    expected result: 1 is peeked
    Actual result:1 is peeked
    returnedStatus: passed
    */

    //steeb
    std::cout << "testing peek:" << '\n';
    queue testq;
    testq.enqueue(1);
    if(testq.peek() != 1)
        std::cout << "peek test failed, peeked value does not match input" << '\n';
    
    /*
    Test ID: peek order check
    Unit: test::peek()
    Description: checks that peek returns the last value in the queue
    data size: 2
    Precondition: numbers 1 and 2 added in sequential indexes, and 2 is peeked before 1
    Postcondition: 2 is peeked
    expected result: 2 is peeked
    Actual result: origionally peek returned the rear value, but that was corrected, and the function now works
    returnedStatus: passed
    */

    queue testq2;
    testq2.enqueue(1);
    testq2.enqueue(2);
    //std::cout << testq2.peek() << '\n';
    if(testq2.peek() != 1)
        std::cout << "peek test failed, queue not returning elements in the correct order";
}
void test::size()
{
    /*
    Test ID:
    Unit:
    Description:
    data size:
    Precondition:
    Postcondition:
    expected result:
    Actual result:
    returnedStatus:
    */


}
void test::isEmpty()
{
    /*
    Test ID: Empty queue check
    Unit: test::isEmpty()
    Description: checks if isEmpty is true, when new empty queue is created
    Test dataSize: 0
    Precondition: default constructor creates an empty queue
    Postcondition: queue remains empty
    Expected result: queue stays empty, and isEmpty returns true
    Actual result: queue stays empty, and isEmpty returns true
    Status: passed
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
    data size:
    Precondition:
    Postcondition:
    expected result:
    Actual result:
    returnedStatus:
    */

}