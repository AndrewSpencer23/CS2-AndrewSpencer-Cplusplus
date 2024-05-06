#include <iostream>
#include <cassert>
#include <string>
#include <sstream>
#include "stack.h"

using namespace std;

void test();

double evaluateRPN(string expression)
{
    stringstream iss;
    Stack<double> myStack;
    string token;
    while (iss >> token) {
        if (isdigit(token[0])) {
            double number;
            stringstream(token) >> number;
            myStack.push(number);
        }
        else {
            double element2 = myStack.pop();
            double element1 = myStack.pop();
            double result;
            switch (token[0]) {
                case '+':
                    result = element1 + element2;
                    break;
                case '-':
                    result = element1 - element2;
                    break;
                case '*':
                    result = element1 * element2;
                    break;
                case '/':
                    if (element2 == 0) {
                        cerr << "Error: Division by zero\n";
                        return 0.0;
                    }
                    result = element1 / element2;
                    break;
                default:
                    cerr << "Error: Unknown operator\n";
                    return 0.0;
            }
            myStack.push(result);
        }
    }
    return myStack.pop();
}

int main(int argc, char *argv[])
{
    cout << "1";
    if(argc >= 2 && (string)argv[1] == "test")
    {
        test();
        return 0;
    }
    if(argc == 3 && (string)argv[1] == "-p") {
        cout << argv[2] << " = " << evaluateRPN(argv[2]);
        return 0;
    }
    string expression;
    cout << "Please enter a RPN string to be evaluated: ";
    cin >> expression;
    cout << expression << " = " << evaluateRPN(expression) << endl;
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