#include <iostream>
using namespace std;

// Hello Ifs
int main() {
    int n;
    float x;
    float sum = 0;
    cin >> n;

    while (n > 0){
        cin >> x;
        sum = sum + x;
        n--;
    }

    std::cout << sum;

    return 0;
}