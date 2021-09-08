#include <iostream>
#include <math.h>

using namespace std;

void primeFactors(int n) {
    bool first = true;

    while (n%2 == 0){
        if(first){
            cout << 2;
            first = false;
        }else{
            cout << " * " << 2;
        }

        n = n/2;
    }

    for (int i = 3; i <= sqrt(n); i = i+2){
        while (n%i == 0){
            if(first){
                cout << i;
                first = false;
            }else{
                cout<< " * " << i;
            }

            n = n/i;
        }
    }

    if (n > 2){
        if(first){
            cout << n;
        }else{
            cout << " * " << n;
        }
    }
}

int main() {
    int n = 0;
    cin >> n;
    primeFactors(n);
    return 0;
}