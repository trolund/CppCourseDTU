#include <iostream>
#include "doubly-linked.h"

int main() {
    List l;
    int n;

    // Print list as read from cin
    l.print();
    // Reverse the list and print it
    l.reverse();
    l.print();
    // Reverse again and print it
    l.reverse();
    l.print();

    return 0;
}
