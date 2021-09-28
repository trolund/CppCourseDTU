#include <iostream>
#include <vector>
#include <math.h>
#include <map>
#include <sstream>

using namespace std;

bool isNumber(const string& str)
{
    for (char const &c : str) {
        if (std::isdigit(c) == 0) return false;
    }
    return true;
}

void tokenize(string const &str, const char delim, vector<string> &out)
{
    // construct a stream from the string
    stringstream ss(str);

    string s;
    while (getline(ss, s, delim)) {
        out.push_back(s);
    }
}

map<char, vector<int>*> getNumbers(string s){
    char delimiter = ' ';
    char key;

    map<char, vector<int>*> m;

    vector<string> out;
    tokenize(s, delimiter, out);

    for (string token : out) {
        if(isNumber(token)){
            m.find(key)->second->push_back(stoi(token));
        }else{
            key = token[0];
            m.insert({key, new vector<int>});
        }
    }

    return m;
}

vector<char> getKeys(map<char, vector<int>*> map){
    vector<char> keys;
    for(auto const& imap: map)
        keys.push_back(imap.first);

    return keys;
}

int main() {
    string input;
    getline(cin, input);
    map<char, vector<int>*> m = getNumbers(input);
    vector<char> keys = getKeys(m);
    sort(keys.begin(), keys.end());

    for (int i = 0; i < 100; ++i) {
        for (char k : keys) {
            vector<int>* x = m.find(k)->second;
            if(i < x->size()){
                int element = x->at(i);
                cout <<  element << " ";
            }

        }
    }

    return 0;
}





