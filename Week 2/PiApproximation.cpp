#include <iostream>
using namespace std;

int main() {
    double k = 1.0;
    double s = 0.0;
    int n = 0;
    cin >> n;

    for (int i = 0; i < n; ++i) {
        if(i % 2 == 0){
            s += 4/k;
        }else {
            s -= 4/k;
        }

        k += 2;
    }

    std::cout << std::fixed;
    std::cout << s;

    return 0;
}