#include <iostream>
#include "ex01-library.h"
using namespace std;

// Task 1(a).  Implement this function
Complex **createMatrix(unsigned int m, unsigned int n, Complex c) {
    // Write your code here
    Complex **A = new Complex*[m];
    for (unsigned int i = 0; i < m; i++) {
        A[i] = new Complex[n];
        for (unsigned int j = 0; j < n; j++) {
            A[i][j] = c;
        }
    }
    return A;
}

// Task 1(b).  Implement this function
void displayMatrix(Complex **A, unsigned int m, unsigned int n) {
    // Write your code here
    for (unsigned int i = 0; i < m; i++) {
        for (unsigned int j = 0; j < n; j++) {
            cout << A[i][j].re << (A[i][j].im >= 0 ? "+" : "") << A[i][j].im << "i";
            if (j != n-1) {
                cout << " ";
            }
        }
        cout << endl;
    }
}

// Task 1(c).  Implement this function
Complex **createIdentityMatrix(unsigned int n) {
    // Write your code here
    Complex zero = {0, 0};
    Complex **A = createMatrix(n, n, zero);

    unsigned int y = 0;

    for (unsigned int i = 0; i < n; i++) {
        for (unsigned int j = 0; j < n; j++) {
            if(j == y){
                A[i][j].re = 1;
            }
        }
        y++;
    }

    return A;
}

// Task 1(d).  Implement this function
void multMatrix(Complex **A, Complex **B, Complex **C, unsigned int m, unsigned int n, unsigned int p) {
    // Write your code here
    for(unsigned int i = 0; i < m; ++i)
        for(unsigned int j = 0; j < p; ++j) {
            C[i][j] = {0, 0};
            for (unsigned int k = 0; k < n; ++k) {
                Complex X = mult(A[i][k], B[k][j]);
                C[i][j] = add(C[i][j], X);
            }
        }
}

// Do not modify
Complex add(Complex c, Complex d) {
    Complex result = { c.re + d.re, c.im + d.im };
    return result;
}

// Do not modify
Complex mult(Complex c, Complex d) {
    Complex result;
    result.re = (c.re * d.re) - (c.im * d.im);
    result.im = (c.re * d.im) + (c.im * d.re);
    return result;
}

// Do not modify
void deleteMatrix(Complex **A, unsigned int nRows) {
    for (unsigned int i = 0; i < nRows; i++) { delete[] A[i]; }
    delete[] A;
}
