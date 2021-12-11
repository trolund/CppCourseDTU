#include <iostream>
#include "ex02-library.h"
using namespace std;

int main() {
    Elem e0 = {10, 5, nullptr};
    Elem e1 = {12, 6, &e0};
    Elem e2 = {4, 10, &e1};

    cout << "Initial list:" << endl;
    displayRLEList(&e2);
    cout << endl;

    Elem *l1 = append(&e2, 10);
    cout << "After we append value 10:" << endl;
    displayRLEList(l1);
    cout << endl;

    Elem *l2 = append(l1, 42);
    cout << "After we append value 42:" << endl;
    displayRLEList(l2);
    cout << endl;

    cout << "If we append 42 to an empty list:" << endl;
    Elem *l3 = append(nullptr, 42);
    displayRLEList(l3);
    cout << endl;

    return 0;
}
