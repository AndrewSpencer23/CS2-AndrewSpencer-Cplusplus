#include "aclass.h"
#include "bclass.h"

using namespace std;

int main(int argc, char* argv[]) {
    bclass::BClass bClassInstance;

    for(int i = 0; i < 10; i++) {
        aclass::AClass* newAClass = new aclass::AClass();
        bClassInstance.setThings(newAClass, i);
    }
    return 0;
}