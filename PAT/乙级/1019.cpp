#include <iostream>
#include <algorithm>

using namespace std;

int main(int argc, char const *argv[])
{
    string str, temp1, result;
    cin >> str;
    int a;
    str.insert(0, 4 - str.length(), '0');
    while (result != "6174")
    {
        sort(str.begin(), str.end());
        temp1 = str;
        reverse(temp1.begin(), temp1.end());
        cout << temp1 << " - " << str << " = ";
        a = stoi(temp1) - stoi(str);
        if (a == 0)
        {
            cout << "0000";
            return 0;
        }
        printf("%04d\n", a);
        str = to_string(a);
        if (str.length() < 4)
            str.insert(0, "0");
        result = str;
    }
    return 0;
}
