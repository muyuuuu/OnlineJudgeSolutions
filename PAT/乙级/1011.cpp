#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    string str;
    long long a, b, c;
    for (int i = 0; i < n; i++)
    {
        cin >> a >> b >> c;
        if (a + b > c)
            str = "true";
        else
            str = "false";
        cout << "Case #" << i + 1 << ": " << str << endl;

    }
    return 0;
}