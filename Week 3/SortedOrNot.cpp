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

    data.erase(data.begin());

    bool sorted = true;

    if(data.size() > 1) {
        for (int i = 0; i < data.size() - 1; ++i) {
            if (data[i] > data[i + 1]) {
                cout << "UNSORTED";
                sorted = false;
                break;
            }
        }
    }

    if(sorted){
        cout << "SORTED";
    }

    return 0;
}



