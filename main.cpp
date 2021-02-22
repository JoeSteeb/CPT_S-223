// This code was taken from https://www.techiedelight.com/queue-implementation-cpp/
// The code has been modified from the original to provide opportunities to learn

#include <iostream>
#include <cstdlib>
#include "testQueue.h"
//#include "queue.h"

/*
Attributes 
1)    The queue class and its functions should have a separate header file and be called in the main.
2)    Comments on queue functions has to be more descriptive.
3)    The destructor function should be delete[] arr or A memory leak will occur.
4)    In the enqueue function The item should be added at the rear not the size
5)    For the function isFull capacity should be returned at size, not size() – 1
6)    As far as I can tell, the most efficient algorithms have been used for the functions.
*/

// main function
int main()
{
    // call your test functions here!
    test::enqueue();
    test::peek();
    test::isEmpty();
    test::dequeue();
    test::size();
    test::isFull();
    return 0;
}

