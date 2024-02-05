#include "bclass.h"

void bclass::BClass::setThings(aclass::AClass* newAClass, int arrIdx) {
    things[arrIdx] = newAClass;
}

bclass::BClass::BClass() {
    someNumber = 42;
}

bclass::BClass::~BClass() {
    std::cout << "Freeing up AClass memory: " << std::endl;
    for(int i = 0; i < 10; i++) {
        delete things[i];
    }
}