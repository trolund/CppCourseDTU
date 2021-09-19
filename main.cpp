#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

int main() {
    string input;
    getline(cin, input);

    string delimiter = " ";
    vector<double> result;
    size_t pos = 0;
    string token;


    while ((pos = input.find(delimiter)) != string::npos) {
        token = input.substr(0, pos);
        result.push_back(stod(token));
        input.erase(0, pos + delimiter.length());
    }

    token = input.substr(0, pos);
    result.push_back(stod(token));

    result.erase(result.begin());

    std::size_t const half_size = result.size() / 2;
    std::vector<double> x(result.begin(), result.begin() + half_size);
    std::vector<double> y(result.begin() + half_size, result.end());

    double sum = 0;

    for (int i = 0; i < x.size(); ++i) {
        sum += x[i] * y[i];
    }

    cout << sum;

    return 0;
}



