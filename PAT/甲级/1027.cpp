#include <iostream>
#include <cmath>
#include <algorithm>
#include <cctype>

using namespace std;

string convert(int num)
{
    string str = to_string(num);
    string a = "";
    while (num != 0)
    {
        if (num % 13 >= 10)
        {
            a.push_back((char)('A' + num % 13 - 10));
        }
        else
            a += to_string(num % 13);
        num = num / 13;
    }
    reverse(a.begin(), a.end());
    if (a.length() == 1)
    {
        a.insert(0, "0");
    }
    return a;
}

int main()
{
    int a, b, c;
    string a1, b1, c1;
    cin >> a >> b >> c;
    if (a == 0) a1 = "00";
    else a1 = convert(a);
    if (b == 0) b1 = "00";
    else b1 = convert(b);
    if (c == 0) c1 = "00";
    else c1 = convert(c);
    cout << '#' << a1 << b1 << c1;
}