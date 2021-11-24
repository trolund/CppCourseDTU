

#include "doubly-linked.h"

List::List() {
    first = nullptr;
}

void List::insert(int n) {
    Node *node = new Node();

    if(!first){
        node->prev = nullptr;
        node->next = nullptr;
        node->val = n;
        first = node;

        return;
    }

    Node *curr = this->first;

    while (curr->next != nullptr){
        curr = curr->next;
    }

    curr->next = node;
    node->prev = curr;
    node->val = n;
}

List::~List(void) {
    if(!first){
        return;
    }

    Node *curr = this->first;

    while (curr->next != nullptr){
        Node *temp = curr;
        curr = curr->next;

        temp->prev = nullptr;
        temp->next = nullptr;
        delete temp;
    }

    first = nullptr;
}

void List::print(void) {
    if(!first){
        return;
    }

    Node *curr = this->first;

    while (curr != nullptr){
        cout << curr->val << " ";
        curr = curr->next;
    }

    cout << "\n";
}

void List::reverse(void) {
    if(!first){
        return;
    }

    Node *curr = first;
    Node *temp;

    while(curr != nullptr){
        temp = curr->prev; //swap the next and prev pointer
        curr->prev = curr->next;
        curr->next = temp;
        curr = curr->prev;
    }

    if(temp){
        first = temp->prev;
    }
}
