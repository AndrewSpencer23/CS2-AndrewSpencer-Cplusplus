#include "fractions.h"

// Constructor
fractions::Fraction::Fraction(int numerator, int denominator) 
{
    if (denominator != 0) {
        _numerator = numerator;
        _denominator = denominator;
    }
    else {
        cout << "Please enter a numerator: ";
        cin >> numerator;
        cout << "Please enter a denominator: ";
        cin >> denominator;
        while (denominator == 0) {
            cout << "You can't divide by zero. Enter a new denominator: ";
            cin >> denominator;
        }
        _denominator = denominator;
        _numerator = numerator;
    }
}

// Arithmetic Operators
fractions::Fraction fractions::Fraction::operator+(const Fraction &frac) 
{
    int commonDenom = _denominator * frac._denominator;
    int num1 = _numerator * frac._denominator;
    int num2 = frac._numerator * _denominator;
    Fraction result(num1 + num2, commonDenom);
    result.simplify();
    return result;
}

fractions::Fraction fractions::Fraction::operator-(const Fraction &frac) 
{
    int commonDenom = _denominator * frac._denominator;
    int num1 = _numerator * frac._denominator;
    int num2 = frac._numerator * _denominator;
    Fraction result(num1 - num2, commonDenom);
    result.simplify();
    return result;
}

fractions::Fraction fractions::Fraction::operator*(const Fraction &frac) 
{
    Fraction result(_numerator * frac._numerator, _denominator * frac._denominator);
    result.simplify();
    return result;
}

fractions::Fraction fractions::Fraction::operator/(const Fraction &frac) 
{
    Fraction result(_numerator * frac._denominator, _denominator * frac._numerator);
    result.simplify();
    return result;
}

// Simplification
fractions::Fraction fractions::Fraction::simplify(Fraction frac) 
{
    int a = gcd(frac._numerator, frac._denominator);
    Fraction newFraction(0, 1);
    newFraction._numerator = frac._numerator / a;
    newFraction._denominator = frac._denominator / a;
    return newFraction;
}

void fractions::Fraction::simplify() 
{
    int a = gcd(_numerator, _denominator);
    _numerator /= a;
    _denominator /= a;
}

// Greatest Common Divisor
int fractions::Fraction::gcd(int a, int b) 
{
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

// Output Operator Overload
std::ostream &fractions::operator<<(std::ostream &os, const Fraction &frac) 
{
    return os << frac._numerator << "/" << frac._denominator;
}

// Equality Operator Overload
bool fractions::Fraction::operator==(const Fraction &frac) 
{
    return _numerator == frac._numerator && _denominator == frac._denominator;
}