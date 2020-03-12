#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    string s, str;
    int m;
    cin >> s >> m;
    int count = 1, flag = 0;
    for (int i = 1; i <= m; i++)
    {
        if (i != 1)
            s = str;
        str = "";
        for (int j = 0; j < s.length(); j++)
        {
            if (j + 1 != s.length())
            {
                int k = j + 1;
                while (s[k] == s[j])
                {
                    count++;
                    flag = 1;
                    k++;
                }
                str += s[j];
                str += to_string(count);
                j = k - 1;
                count = 1;
            }
            if (j == s.length() - 1 && flag == 0)
            {
                str += s[j];
                str += '1';
                // cout << str << ".." << endl;
            }
            flag = 0;
        }
    }
    cout << s;
    return 0;
}
