#include <iostream>

using namespace std;

template <class T1, class T2, class T3>
T1 addNums(T2, T3);


int main(int argc, char* argv[]) {
    float num1;
    int num2;
    float result;

    num1 = 42.15;
    num2 = 15;

    result = addNums<float, float, int>(num1, num2);
    cout << num1 << " + " << num2 << " = " << result << endl;
    cout << "3000 + 68.3 = " << addNums<float,int,float>(3000, 68.3);
    return 0;
}

template <class T1, class T2, class T3>
T1 addNums(T2 n1, T3 n2) {
    T1 sum;
    sum = n1 + n2;
    return sum;
}