#include <iostream>
#include "ex02-library.h"
using namespace std;

// Task 2(a).  Implement this function
unsigned int length(Elem *list) {
    if(list == 0){
        return 0;
    }

    // Write your code here
    Elem* curr = list;
    unsigned int count = 0;

    while (curr != NULL) {
        count += curr->times;
        curr = curr->next;
    }

    return count;
}

// Task 2(b).  Implement this function
Elem* append(Elem *list, int v) {
    Elem* newNode = new Elem();
    newNode->value = v;
    newNode->times = 1;

    if(list == NULL){
        return newNode;
    }

    Elem* curr = list;
    Elem* prev;

    while (curr != NULL) {
        if(curr->value == v){
            curr->times++;
            return list;
        }
        prev = curr;
        curr = curr->next;
    }

    prev->next = newNode;

    return list;
}

// Task 2(c).  Implement this function
Elem* buildRLEList(int *data, unsigned int n) {
    // Write your code here
    Elem* head = new Elem();
    head->value = data[0];
    head->times = 1;

    for (unsigned int i = 1; i < n; ++i) {
        head = append(head, data[i]);
    }

    return head;
}

// Do not modify
void displayRLEList(Elem *list) {
    if (list == nullptr) {
        return;
    }
    cout << " " << list->value << " (x" << list->times << ")";
    displayRLEList(list->next);
}
