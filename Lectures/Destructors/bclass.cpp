#include "bclass.h"

void BClass::setThings(AClass* newAClass, int arrIdx) {
    things[arrIdx] = newAClass;
}

BClass::BClass() {
    someNumber = 42;
}

BClass::~BClass() {
    std::cout << "Freeing up AClass memory: " << std::endl;
    for(int i = 0; i < 10; i++) {
        delete things[i];
    }
}