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

int main() {

    string input;
    getline(cin, input);

    vector<int> list = getNumbers(input);

    for (int i = list.size() - 1; i >= 0; --i) {
       cout << list[i] << " ";
    }

    return 0;
}
