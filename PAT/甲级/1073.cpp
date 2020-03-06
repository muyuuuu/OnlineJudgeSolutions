#include <iostream>
#include <cmath>

using namespace std;

int main(int argc, char const *argv[])
{
    string s;
    cin >> s;
    int flag = 0;
    s[0] == '-' ? flag = 1 : flag = 0;
    int pos = s.find_first_of("E");
    int pos1 = s.find_first_of(".");
    string s1 = s.substr(pos + 1);
    int a = stoi(s1);
    if (flag == 1)
        cout << "-";
    if (a < 0)
    {
        string s2 = s.substr(1, pos1 - 1);
        if (abs(a) >= s2.length())
        {
            cout << "0.";
            for (int i = 0; i < abs(a) - s2.length(); i++)
                cout << "0";
            for (int i = 1; i < pos; i++)
            {
                if (s[i] == '.')
                    continue;
                else
                    cout << s[i];
            }
        }
        else
        {
            s.erase(pos1, 1);
            s.insert(pos1 - a, ".");
            for (int i = 1; i < pos; i++)
                cout << s[i];
        }
    }
    if (a > 0)
    {
        string s2 = s.substr(pos1 + 1, pos - pos1 - 1);
        // +1.2E+10
        if (a >= s2.length())
        {
            for (int i = 1; i < pos; i++)
            {
                if (s[i] == '.')
                    continue;
                else
                    cout << s[i];
            }
            for (int i = 0; i < a - s2.length(); i++)
                cout << "0";
        }
        // +1.263232E+03
        if (a < s2.length())
        {
            s.erase(pos1, 1);
            s.insert(pos1 + a, ".");
            for (int i = 1; i < pos; i++)
                cout << s[i];
        }
    }
    // +1.20202020000E+0
    if (a == 0)
    {
        for (int i = 1; i < s.length() - s1.length() - 1; i++)
            cout << s[i];
    }
    return 0;
}
