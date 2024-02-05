#include "aclass.h"
#include "bclass.h"

using namespace std;

int main(int argc, char* argv[]) {
    BClass bClassInstance;

    for(int i = 0; i < 10; i++) {
        AClass* newAClass = new AClass();
        bClassInstance.setThings(newAClass, i);
    }
    return 0;
}