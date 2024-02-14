#include <iostream>

using namespace std;

class SomeClass {
    private:
    int _id;
    int _otherId;

    public:
    SomeClass& setId(int);
    SomeClass& setOtherId(int);

    int getOtherId();
    int getId();
};

int main(int argc, char* argv[]) {
    SomeClass sc1;
    sc1.setId(42);
    sc1.setOtherId(15);
    cout << sc1.getId() << endl;
    return 0;
}

SomeClass& SomeClass::setId(int id) {
    this->_id = id;
    return *this;
}


int SomeClass::getId() {
    return this->_id;
}

SomeClass& SomeClass::setOtherId(int otherId) {
    this->_otherId = otherId;
    return *this;
}
int SomeClass::getOtherId() {
    return this->_otherId;
}