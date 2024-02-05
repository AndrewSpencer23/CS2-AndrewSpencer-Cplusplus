#pragma once
#include "aclass.h"
#include <iostream>

namespace bclass {
    class BClass {
        private:
        int someNumber;
        aclass::AClass* things[];

        public:
        BClass();
        ~BClass();
        void setThings(aclass::AClass*, int);
    };
}