//
// Created by Troels Lund on 02/10/2021.
//

#include "fraction.h"
#include <iostream>

using namespace std;

Fraction::Fraction(int x, int y)
{
    this->denominator = x;
    this->numerator = y;
}

void Fraction::add(Fraction f)
{
    this->denominator = f.denominator + f.denominator;
}

void Fraction::div(Fraction f)
{
    this->denominator = f.denominator / f.denominator;
}
void Fraction::mult(Fraction f)
{
    this->denominator = f.denominator * f.denominator;
}

void Fraction::display()
{
    cout << this->denominator << " / " << this->numerator;
}