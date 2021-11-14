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

bool isPalindrome(vector<int> list)
{
    int l = 0;
    int r = list.size() - 1;

    while (r > l)
    {
        int left = list[l++];
        int right = list[r--];

        if (left != right)
        {
            return false;
        }
    }
    return true;
}


int main() {

    string input;
    getline(cin, input);

    vector<int> list = getNumbers(input);

    bool x = isPalindrome(list);

    cout << (x ? "yes" : "no");

    return 0;
}

