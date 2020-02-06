#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int main()
{
    int a, b, c;
    cin >> a >> b;
    c = a * b;
    if (c >= 0)
    {
        string str = to_string(c);
        reverse(str.begin(), str.end());
        cout << stoi(str);
    }
    else
    {
        c = abs(c);
        string str = to_string(c);
        reverse(str.begin(), str.end());
        cout << "-" << stoi(str);
    }
    return 0;
}