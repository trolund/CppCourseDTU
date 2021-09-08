#include <iostream>
using namespace std;

int main() {
    int *memory = new int[1000];
    int n = -1;

    while(n!=0){
        cin >> n;
        if(n!=0){
            std::cout << memory[n] << endl;
            memory[n]++;
        }
    }

    return 0;
}