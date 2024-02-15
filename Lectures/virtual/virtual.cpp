#include <iostream>

using namespace std;

class Base {
    public:
    virtual void print();
    virtual void show();
};

class Derived : public Base {
    public:
    // void print();
    void show();
};

int main(int argc, char* argv[]) {
    Derived d1;

    d1.Base::print();
    d1.show();
    return 0;
}

Base::print() {
    cout << "Inside Base Print" << endl;
}