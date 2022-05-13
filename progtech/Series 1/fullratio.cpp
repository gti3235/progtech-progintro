#include <iostream>
#ifndef CONTEST
#include "fullratio.hpp"
#endif

using namespace std;

int gcd(int a, int b)
{
    a = abs(a);
    b = abs(b);
    while (a > 0 && b > 0)
        if (a > b)
            a = a % b;
        else
            b = b % a;
    return (a + b);
};

rational::rational(int n, int d)
{
    nom = n;
    den = d;
}

rational operator+(const rational &x, const rational &y)
{
    return rational((x.nom * y.den + y.nom * x.den), x.den * y.den);
}

rational operator-(const rational &x, const rational &y)
{
    return rational((x.nom * y.den - y.nom * x.den), x.den * y.den);
}

rational operator*(const rational &x, const rational &y)
{
    return rational(x.nom * y.nom, x.den * y.den);
}

rational operator/(const rational &x, const rational &y)
{
    return rational(x.nom * y.den, x.den * y.nom);
}

std::ostream &operator<<(std::ostream &out, const rational &x)
{
    int divider = gcd(x.nom, x.den);
    if (x.nom / divider != 0)
    {
        if (x.den / divider < 0)
        {
            if (x.nom / divider < 0)
                out << abs(x.nom / divider) << "/" << abs(x.den / divider);
            else
                out << "-" << x.nom / divider << "/" << abs(x.den / divider);
        }
        else
            out << x.nom / divider << "/" << x.den / divider;
    }
    else
        out << abs(x.nom / divider) << "/" << abs(x.den / divider);
    return out;
}
