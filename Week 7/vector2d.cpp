#include "vector2d.h"
#include <cmath>
#include <iostream>

using namespace std;

v2d::v2d(double a, double b) {
    this->y = b;
    this->x = a;
}

v2d::v2d(const v2d & v) {
    this->y = v.y;
    this->x = v.x;
}

v2d::~v2d() {
    // cout << "v2d is being deleted" << endl;
}

v2d & v2d::operator=(const v2d &v) {
    this->x = v.x;
    this->y = v.y;
    return *this;
}

v2d & v2d::operator+(const v2d &v) {
    this->x += v.x;
    this->y += v.y;
    return *this;
}

double v2d::operator*(const v2d &v) {
    return this->x * v.x + this->y * v.y;
}

v2d & v2d::operator*(double k) {
    this->y *= k;
    this->x *= k;
    return *this;
}

double v2d::length() {
    return sqrt(pow(this->x,2) +pow(this->y,2));
}

