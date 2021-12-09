#include <iostream>
#include "ex02-library.h"
using namespace std;

// Task 2(a).  Implement this function
Elem* reverse(Elem *list) {
    Elem* curr = list;
    Elem *prev = NULL, *next = NULL;

    while (curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    return prev;
}

Elem* FindTail(Elem *list){
    Elem* curr = list;

    while (curr->next != nullptr){
        curr = curr->next;
    }

    return curr;
}

// Task 2(b).  Implement this function
Elem* concatenate(Elem *list1, Elem *list2) {
    if(list1 == NULL){
        return list2;
    }

    if(list2 == NULL){
        return list1;
    }

    Elem* tail = FindTail(list1);

    if(tail->value == list2->value){
        tail->next = list2->next;
        tail->times += list2->times;
    }else {
        tail->next = list2;
    }

    return list1;
}

// Task 2(c).  Implement this function
int sum(Elem *list) {
    int sum = 0;
    Elem* curr = list;

    while (curr != NULL){
        sum += curr->value * curr->times;
        curr = curr->next;
    }

    return sum;
}

// Do not modify
void displayRLEList(Elem *list) {
    if (list == nullptr) {
        return;
    }
    cout << " " << list->value << " (x" << list->times << ")";
    displayRLEList(list->next);
}
