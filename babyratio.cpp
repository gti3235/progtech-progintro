#include <iostream>
#ifndef CONTEST
#include "babyratio.hpp"
#endif

using namespace std;

int rational::gcd(int a, int b)
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
    if (nom == 0)
        nom = abs(nom);
}

rational rational::add(rational r)
{
    return rational((nom * r.den + r.nom * den), den * r.den);
}

rational rational::sub(rational r)
{
    return rational((nom * r.den - r.nom * den), den * r.den);
}

rational rational::mul(rational r)
{
    return rational(nom * r.nom, den * r.den);
}

rational rational::div(rational r)
{
    return rational(nom * r.den, den * r.nom);
}

void rational::print()
{
    int divider = gcd(nom, den);
    if (nom / divider != 0)
    {
        if (den / divider < 0)
        {
            if (nom / divider < 0)
                printf("%d/%d", abs(nom / divider), abs(den / divider));
            else
                printf("-%d/%d", nom / divider, abs(den / divider));
        }
        else
            printf("%d/%d", nom / divider, den / divider);
    } else printf("%d/%d", abs(nom / divider), abs(den / divider));
}