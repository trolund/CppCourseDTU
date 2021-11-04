//
// Created by Troels Lund on 02/10/2021.
//

#ifndef C__COURSE_FRACTION_H
#define C__COURSE_FRACTION_H


class Fraction {
private: // Internal representation of a fraction as two integers
    int numerator;
    int denominator;

public: // Class constructor

    Fraction(int n, int d);
// Methods to update the fraction
void add(Fraction f);
void mult(Fraction f);
void div(Fraction f);
// Display method
void display(void);
} ;


#endif //C__COURSE_FRACTION_H
