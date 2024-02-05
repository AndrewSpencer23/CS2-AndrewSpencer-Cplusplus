#pragma once
#include "aclass.h"
#include <iostream>

class BClass {
    private:
    int someNumber;
    AClass* things[];

    public:
    BClass();
    ~BClass();
    void setThings(AClass*, int);
};