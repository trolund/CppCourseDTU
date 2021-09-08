#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

vector<int> getNumbers(){
    string s;
    getline(cin, s);

    string delimiter = " ";
    vector<int> result;

    if(s.length() > 10){
        s += " ";



        size_t pos = 0;
        int number;

        while ((pos = s.find(delimiter)) != string::npos) {
            number = stoi(s.substr(0, pos));
            result.push_back(number);
            s.erase(0, pos + delimiter.length());
        }
    }else if(s.length() < 3) {
        result.push_back(stoi(s));

        while (getline(cin, s)){
            if(s == "" || s == " "){
                break;
            }
            int number = stoi(s);
            result.push_back(number);
        }
    }else {
        int pos = s.find(delimiter);
        int x = stoi(s.substr(0, pos));
        s.erase(0, pos + delimiter.length());
        int y = stoi(s.substr(0, s.find(delimiter)));
        result.push_back(x);
        result.push_back(y);

        while (getline(cin, s)){
            if(s == "" || s == " "){
                break;
            }
            int number = stoi(s);
            result.push_back(number);
        }
    }

    return result;
}

int max(vector<int> data){
    int max = 0;
    for (int x : data) {
        if(x > max){
            max = x;
        }
    }

    if(max > 100){
        max = 100;
    }

    return max;
}

int main() {
    vector<int> data = getNumbers();

    double l = data[0]; // number of intervals (bucket size))
    double n = data[1]; // amount of data (length)

    int m = max(data);
    int k = ceil(m / l); // interval size

    int* memory = new int[100000];

    // init array
    for (int i = 0; i < n; ++i) {
        memory[i] = 0;
    }

    for (int i = 2; i < n + 2; ++i) {
        if(data[i] == m && m % data[0] == 0){
            memory[(m/k)-1] += 1;
        }else{
            int bucket = (int) floor(data[i] / k);
            memory[bucket] += 1;
        }
    }

    for (int i = 0; i < l; i++) {
        cout << i * k << ": " << memory[i] << endl;
    }

    return 0;
}



