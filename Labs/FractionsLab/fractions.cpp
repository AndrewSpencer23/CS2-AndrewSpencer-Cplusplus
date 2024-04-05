#include "fractions.h"

fractions::Fraction::Fraction(int numerator, int denominator)
{
    _numerator = numerator;
    _denominator = denominator;
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
    return Fraction(0, 1);
}

void fractions::Fraction::simplify()
{
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