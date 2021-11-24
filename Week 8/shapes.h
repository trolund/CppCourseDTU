//
// Created by Troels Lund on 17/10/2021.
//

#ifndef WEEK8_SHAPES_H
#define WEEK8_SHAPES_H
#include <math.h>

class Shape {
public:
    virtual double area() = 0;
    virtual double perimeter() = 0;
    virtual double height() = 0;
    virtual double width() = 0;
    virtual void rotate(){}
};


class Rectangle: public Shape {
    double w;
    double h;

public:
    Rectangle(double h, double w) : w(w), h(h) {}

    double area() override{
        return h * w;
    }

    double perimeter() override{
        return w * 2 + h * 2;
    }
    double height() override{
        return h;
    }

    double width() override{
        return w;
    }

    void rotate() override{
        double temp = h;
        h = w;
        w = temp;
    }
};

class Square: public Shape  {
    double length;

public:
    Square(double length) : length(length) {}

    double area() override{
        return length * length;
    }

    double perimeter() override{
        return length * 4;
    }
    double height() override{
        return length;
    }

    double width() override{
        return length;
    }
};

class Circle: public Shape  {
    double radius;
public:
    Circle(double radius) : radius(radius) {}

    double area() override{
        return M_PI * radius * radius;
    }

    double perimeter() override{
        return 2 * M_PI * radius;
    }
    double height() override{
        return radius * 2;
    }

    double width() override{
        return radius * 2;
    }
};

#endif //WEEK8_SHAPES_H
