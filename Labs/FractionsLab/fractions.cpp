#include "fractions.h"

fractions::Fraction::Fraction(int numerator, int denominator)
{
    if(denominator != 0) {
        _numerator = numerator;
        _denominator = denominator;
    }
    else if(denominator == 0) {
        cout << "Please enter a numerator" << endl;
        cin >> numerator;
        cout << "Please enter a denominator" << endl;
        cin >> denominator;
        while(denominator == 0) {
            cout << "You cant divide by zero, you must enter a new denominator: " << endl;
            cin >> denominator;
        }
        _denominator = denominator;
        _numerator = numerator;
    }
    else {
        cout << _numerator << '/' << _denominator << endl;
    }
}

fractions::Fraction fractions::Fraction::operator+(fractions::Fraction const &frac)
{
    int commonDenom = 0;
    commonDenom = _denominator * frac._denominator;

    int num1, num2;
    num1 = _numerator * frac._denominator;
    num2 = frac._numerator * _denominator;

    _numerator = num1 + num2;
    _denominator = commonDenom;

    return Fraction(_numerator, _denominator);
}

fractions::Fraction fractions::Fraction::operator-(fractions::Fraction const &frac)
{
    int commonDenom = 0;
    commonDenom = _denominator * frac._denominator;

    int num1, num2;
    num1 = _numerator * frac._denominator;
    num2 = frac._numerator * _denominator;

    _numerator = num1 - num2;
    _denominator = commonDenom;

    return Fraction(_numerator, _denominator);
}

fractions::Fraction fractions::Fraction::operator*(Fraction const &frac)
{
    _numerator = _numerator * frac._numerator;
    _denominator = _denominator * frac._denominator;

    return Fraction(_numerator, _denominator);
}

fractions::Fraction fractions::Fraction::operator/(Fraction const &frac)
{
    _numerator = _numerator * frac._denominator;
    _denominator = _denominator * frac._numerator;

    return Fraction(_numerator, _denominator);
}

fractions::Fraction fractions::Fraction::simplify(Fraction frac)
{
    Fraction newFraction(0,1);
    int a;
    a = gcd(frac._numerator, frac._denominator);
    newFraction._numerator = frac._numerator / a;
    newFraction._denominator = frac._denominator / a;
    return Fraction(newFraction);
}

void fractions::Fraction::simplify()
{
    Fraction newFraction(0,1);
    int a;
    a = gcd(_numerator, _denominator);
    newFraction._numerator = _numerator / a;
    newFraction._denominator = _denominator / a;
}

int fractions::Fraction::gcd(int a, int b)
{
    return 0;
}

bool fractions::Fraction::operator==(Fraction const &frac)
{
    return false;
}

ostream &fractions::operator<<(ostream &os, const Fraction &frac)
{
    return os;
}