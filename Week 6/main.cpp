#include <iostream>
#include <vector>
#include "fraction.h"

using namespace std;

int main()
{
    int i = 0;

    int a, b, c, d = INT_MIN;
    char co;

    cout << "input start!";

    while (!cin.fail() || i == 4)
    {
        char input;
        if (input != ' ' || '/')
        {
            if (i == 0)
            {
                a = input;
            }
            else if (i == 1)
            {
                b = input;
            }
            else if (i == 2)
            {
                co = input;
            }
            else if (i == 3)
            {
                c = input;
            }
            else if (i == 4)
            {
                d = input;
            }
            ++i;
            cout << input << " " << i;
        }
    }

    Fraction x = Fraction(a, b);
    Fraction y = Fraction(c, d);

    if (co == '+')
    {
        x.add(y);
        x.display();
    }

    return 0;
}
