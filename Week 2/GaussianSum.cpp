#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n; // get user input from the keyboard

    int sum = 0;
    for (int i = 0; i <= n; ++i) {
        sum += i;
    }

    cout << sum;
    return 0;
}
