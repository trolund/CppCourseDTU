#include <iostream>
#include "ex03-library.h"
using namespace std;

// Do not modify
GroceryList::GroceryList() {
    this->items.push_back("Lasagne");
    this->itemsInfo["Lasagne"] = {1, "With eggs if available"};

    this->items.push_back("Salmon");
    this->itemsInfo["Salmon"] = {500, "Smoked if available"};

    this->items.push_back("Spinach");
    this->itemsInfo["Spinach"] = {300, "Fresh"};

    this->items.push_back("Dessert");
    this->itemsInfo["Dessert"] = {8, "Maybe lagkage?"};
}

// Task 3(a).  Implement this method
void GroceryList::add(string name, unsigned int quantity, string notes) {
    if(this->itemsInfo.find(name) == this->itemsInfo.end()){
        this->items.push_back(name);
        this->itemsInfo[name] = {quantity, notes};
    }else{
        this->itemsInfo[name].quantity += quantity;

        if(this->itemsInfo[name].notes.size() == 0){
            this->itemsInfo[name].notes = notes;
        } else{
            this->itemsInfo[name].notes += ";" + notes;
        }
    }
}

// Task 3(b).  Implement this method
bool GroceryList::remove(string name, unsigned int quantity) {
//    // element not in the list (a)
    if (this->itemsInfo.find(name) == this->itemsInfo.end()) {
        return false;
    }

    if(this->itemsInfo[name].quantity < quantity){
        return false;
    }

    this->itemsInfo[name].quantity -= quantity;

    if(this->itemsInfo[name].quantity == 0){
        // remove form list
        this->items.erase(std::remove(this->items.begin(), this->items.end(), name), this->items.end());
        // remove from map
        this->itemsInfo.erase (name);
    }

    return true;
}

// Task 3(c).  Implement this method
bool GroceryList::copyEntry(string name, string newName) {
    if(this->itemsInfo.find(newName) != this->itemsInfo.end() || this->itemsInfo.find(name) == this->itemsInfo.end()){
        return false;
    }else{
        this->items.push_back(newName);
        this->itemsInfo[newName] = this->itemsInfo[name];
    }
    return true;
}

// Do not modify
void GroceryList::display() {
    // Write your code here
    for (auto it = this->items.begin(); it != this->items.end(); it++) {
        Info &item = this->itemsInfo[*it];
        cout << "name='" << *it << "'; ";
        cout << "quantity=" << item.quantity << "; ";
        cout << "notes='" << item.notes << "'" << endl;
    }
}