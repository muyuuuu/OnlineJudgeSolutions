#include <iostream>
#include <algorithm>

using namespace std;

int main(int argc, char const *argv[])
{
    int a, b, c, d;
    cin >> a >> b >> d;
    c = a + b;
    string str;
    if (c == 0)
    {
        cout << "0" << endl;
        return 0;
    }
    while(c != 0)
    {
        str += to_string(c % d);
        c = c / d;
    }
    reverse(str.begin(), str.end());
    cout << str;
    return 0;
}
