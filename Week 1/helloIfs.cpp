#include <iostream>
using namespace std;

// Hello Ifs
int main() {
    int x, y;
    cin >> x;
    cin >> y;

    if(x > y){
        cout << x << " is bigger than " << y;
    }else if(x < y){
        cout << x << " is smaller than " << y;
    }else if(x == y) {
        cout << x << " is equal to " << y;
    }
    return 0;
}