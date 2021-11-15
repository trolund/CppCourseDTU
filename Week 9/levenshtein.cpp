#include <iostream>
#include <vector>

using namespace std;

int min(int x, int y){
    return x < y ? x : y;
}

int f(string x, string y){
    return x == y ? 0 : 1;
}

string suffix(string x){
    return x.substr(1, x.size());
}

string firstElement(string x){
    return x.substr(0, 1);
}

int d(string v, string u){
    // |v|
    if(v.size() == 0)
    {
        return 0;
    }
    // |u|
    else if(u.size() == 0)
    {
        return 0;
    }
    // otherwise
    else {
        int case1 = d(suffix(u), v) + 1;
        int case2 = d(u, suffix(v)) + 1;
        int case3 = d(suffix(u), suffix(v)) + f(firstElement(u), firstElement(v));

        return min(min(case1, case2), case3);
    }
}

int main() {

    string input;
    getline(cin, input);

    string delimiter = " ";

    string wordOne = input.substr(0, input.find(delimiter));
    string wordTwo = input.substr(input.find(delimiter) + 1, input.size());

    cout << d(wordOne, wordTwo);

    return 0;
}

