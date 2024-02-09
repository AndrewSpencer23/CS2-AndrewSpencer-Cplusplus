#include "person.h"

string person::Person(string name, int age, int height) {
    _name = name;
    _age = age;
    _height = height;
    cout << "Creating a new person." << endl;
}

string person::Person::getName() {
    return _name;
}