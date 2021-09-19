#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

vector<int> getNumbers(string s){
    string delimiter = " ";
    vector<int> result;
    size_t pos = 0;
    string token;

    while ((pos = s.find(delimiter)) != string::npos) {
        token = s.substr(0, pos);
        result.push_back(stoi(token));
        s.erase(0, pos + delimiter.length());
    }

    token = s.substr(0, pos);
    result.push_back(stoi(token));

    return result;
}

int main() {
    string input;
    getline(cin, input);

    vector<int> data = getNumbers(input);

    int max = 0;

    for (int i = 1; i < data.size(); ++i) {
        if(max < data[i]){
            max = data[i];
        }
    }

    bool first = true;

    for (int i = 1; i < data.size(); ++i) {
        if(data[i] == max && first){
            cout << "*" << data[i] << "* ";
            first = false;
        }else{
            cout << "" << data[i] << " ";
        }
    }

    return 0;
}



