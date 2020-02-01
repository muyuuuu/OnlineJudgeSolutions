#include <iostream>

using namespace std;

int main ()
{
    bool flag[256] = {false};
    string str1, str2;
    getline(cin, str1);
    getline(cin, str2);
    string result;
    for (int i = 0; i < str1.size(); i++)
    {
        if (str1[i] >= 'a' && str1[i] <= 'z')
            str1[i] -= 32;
        flag[str1[i]] = true;
    }
    for (int i = 0; i < str2.size(); i++)
    {
        if (str2[i] >= 'a' && str2[i] <= 'z')
            str2[i] -= 32;
        flag[str2[i]] = false;
    }
    for (int i = 0; i < str1.size(); i++)
    {
        if (flag[str1[i]] == true)
        {
            if (result.size() == 0)
            {
                result += str1[i];
            }
            else
            {
                int temp = 0;
                for (int j = 0; j < result.size(); j++)
                {
                    if (result[j] == str1[i])
                        temp = 1;
                }
                if (temp == 0)
                {
                    result += str1[i];
                }
            }
        }
    }
    cout << result;
    return 0;
}