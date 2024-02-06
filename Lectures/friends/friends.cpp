#include <iostream>

using namespace std;

class Rectangle {
    private:
    int _side1, _side2;

    public:
    Rectangle(int, int);

    friend int calcArea(Rectangle&);
    friend void setVals(Rectangle&);
};

int calcArea(Rectangle&);
void setVals(Rectangle&);

int main(int argc, char* argv[]) {
    Rectangle rect1(10,2);

    setVals(rect1);

    cout << "The area of our rectangle is: " << calcArea(rect1) << endl;
    return 0;
}

void setVals(Rectangle& r1) {
    cout << "Enter side 1: ";
    cin >> r1._side1;
    cout << "Enter side 2: ";
    cin >> r1._side2;
}

int calcArea(Rectangle& r1) {
    int area;
    area = r1._side1 * r1._side2;
    return 0;
}

Rectangle::Rectangle(int side1, int side2) {
    _side1 = side1;
    _side2 = side2;
}

