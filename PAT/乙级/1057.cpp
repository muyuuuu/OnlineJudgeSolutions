#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    string str;
    int key = 0;
    getline(cin, str);
    for (int i = 0; i < str.length(); i++)
    {
        if (isalpha(str[i]))
        {
            if (str[i] >= 'a' && str[i] <= 'z')
            {
                key += str[i] - 'a' + 1;
            }
            else
            {
                key += str[i] - 'A' + 1;
            }
        }
    }
    int a = 0, b = 0;
    str = "";
    while(key != 0)
    {
        str += to_string(key % 2);
        key = key / 2;
    }
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == '0')
            a++;
        if (str[i] == '1')
            b++;
    }
    cout << a << " " << b;
    return 0;
}
