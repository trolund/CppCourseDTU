#include <iostream>
#include <vector>
#include <math.h>

using namespace std;



vector<int> getNumbers(string s){
    string delimiter = " ";
    vector<int> result;
    size_t pos = 0;
    string token;

    if(s.empty()){
        return result;
    }

    while ((pos = s.find(delimiter)) != string::npos) {
        token = s.substr(0, pos);
        result.push_back(stoi(token));
        s.erase(0, pos + delimiter.length());
    }

    token = s.substr(0, pos);
    result.push_back(stoi(token));

    return result;
}

int fib(int n){
    if (n == 0 || n == 1){
        return 1;
    }
    else{
        return fib(n-1)+fib(n-2);
    }
}

int main() {

    string input;
    getline(cin, input);

    vector<int> list = getNumbers(input);

    for (int i = 0; i < list.size(); ++i) {
        cout << fib(list[i]) << " ";
    }

    return 0;
}

