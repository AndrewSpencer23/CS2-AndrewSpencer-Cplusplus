#include <iostream>
#include <cassert>
#include "stack.h"

using namespace std;

void test();

int main(int argc, char* argv[])
{
    if(argc >= 2 && (string)argv[1] == "test")
    {
        test();
        return 0;
    }
    Stack<int> myStack;
    int insertNumber = 0;

    cout << "Enter -999 to quit entering elements: ";
    cin >> insertNumber;
    while(insertNumber != -999)
    {
        myStack.push(insertNumber);
        cout << "Enter -999 to quit entering elements: ";
        cin >> insertNumber;
    }
    
    cout << "You entered " << myStack.size() << " elements into the stack." << endl;
    cout << "The entire stack is: " << myStack << endl;



    return 0;
}

void test()
{
    Stack<int> testStack1;
    size_t stackSize = 10;
    for(size_t i = 0; i < stackSize; i++)
    {
        testStack1.push(i*42);
        assert(testStack1.size() == i + 1);
    }
    assert(testStack1.empty() == false);
    assert(testStack1.size() == 10);
    for(size_t i = 0; i < stackSize; i++)
    {
        assert((size_t)testStack1.pop() == i*42);
        assert(testStack1.size() == stackSize - i - 1);
    }
    assert(testStack1.empty() == true);

    cout << "All test cases passed" << endl;
}