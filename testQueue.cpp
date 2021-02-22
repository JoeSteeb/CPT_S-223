#include "testQueue.h"
#include "queue.h"
#include <iostream>

void test::dequeue()
{
    /*
    Test ID: dequeue element check
    Unit: test::dequeue()
    Description: fills up the queue with a list of increasing numbers, and checks if the orders the same on the way out
    data size: Maximum size of the queue
    Precondition: list filled with increasing numbers
    Postcondition: elements peeked then removed in the same order as they were added
    expected result: elements peeked then removed in the same order as they were added
    Actual result: elements peeked then removed in the same order as they were added
    returnedStatus: passed
    */
    
    std::cout << "testing dequeue:" << '\n';

    queue testq;
    for(int i = 0; i < testq.getCapacity(); i++)
    {
        testq.enqueue(i);
        std::cout <<"size:" << testq.size() <<'\n';
    }

    for(int i = 0; i < testq.getCapacity(); i++)
    {
        if(testq.peek() != i)
            std::cout << "dequeu test failed, removing in the wrong order";

        testq.dequeue();
    }

    /*
    Test ID: dequeue empty check
    Unit: test::dequeue()
    Description: creates empty queue and attempts a dequeue
    data size: 0
    Precondition: empty queue created
    Postcondition: dequeue results in error message and program terminates
    expected result: dequeue results in error message and program terminates
    Actual result: dequeue results in error message and program terminates
    returnedStatus: passed
    */

    queue testq2;
    std::cout << "program should underflow and terminate \n";
    testq.dequeue();
}
void test::enqueue()
{
    /*
    Test ID: enque push and check
    Unit: test::enqueue()
    Description: fills up a queue with 1's and checks all elements
    data size: maximum size of queue
    Precondition: peek and dequeue functioning
    Postcondition: queue is full 
    expected result: queue is full with 1's
    Actual result: initially the resultent queue contained the size of the queue in each element.
    The function was fixed and is now working.
    Status: failed
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
    std::cout << "program should overflow and terminate:" << '\n';
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
    returnedStatus: failed
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
    Test ID: size check
    Unit: test::size()
    Description: fills up list, checking after each enqueue.
    data size: maximum size of queue
    Precondition: 1 added repeatedly to fill queue, size checked after each loop to verify it is growing correctly
    Postcondition: size grows with index of loop
    expected result: size grows with index of loop
    Actual result: initially the size was off by 1, but it has been fixed
    returnedStatus: failed
    */
    std::cout << "testing size: " << '\n';
    queue testq;

    for(int i = 1; i <= testq.getCapacity(); i++)
    {
        testq.enqueue(1);
        //std::cout << "size:" << testq.size() << "i = " << i << '\n';
        if(testq.size() != i)
            std::cout << "size test failed inccorect size returned";
    }
}
void test::isEmpty()
{
    /*
    Test ID: Empty queue check
    Unit: test::isEmpty()
    Description: checks if isEmpty is true, when new empty queue is created
    Test dataSize: 0
    Precondition: empty queue created
    Postcondition: queue remains empty
    Expected result: queue stays empty, and isEmpty returns true
    Actual result: queue stays empty, and isEmpty returns true
    Status: passed
    */

    //steeb
    std::cout << "testing isEmpty:" << '\n';
    queue testq;

    if(!testq.isEmpty())
        std::cout << "isEmpty test failed, program faild to recognize newly created queue" << '\n';
}
void test::isFull()
{
    /*
    Test ID: full test
    Unit: test::isFull()
    Description: fills up que and checks if full while and after filling
    data size: size of capacity
    Precondition: queue is filled up with 1's and checked after each loop
    Postcondition: queue is filled with 1's and isFull() returns true 
    expected result: isFUll returns true
    Actual result: test initially failed, returned not full when full, was fixed by removing +1 from size()
    returnedStatus:failed
    */

    std::cout << "testing isFull:" << '\n';

    queue testq;

    for(int i = 1; i <= testq.getCapacity(); i++)
    {
        testq.enqueue(1);
        if(testq.isFull() && i != testq.getCapacity())
            std::cout << "full test failed, returned full when not full";
    }

    if(!testq.isFull())
        std::cout << "full test failed, returned not full when full";

}