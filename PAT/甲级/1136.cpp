#include <iostream>
#include <algorithm>

using namespace std;

int ispal(string str)
{
    int flag = 0;
    int len = str.length();
    if (str[0] < '0')
        return 0;
    if (str[0] == '0' && str.length() == 1)
        return 1;
    else
        for (int i = 0; i < len ; i++)
            if (str[i] != str[len-1-i])
                flag = 1;
    if (flag == 1)
        return 0;
    else
        return 1;
}

string add(string str, string str1)
{
    int len = str1.length();
    string s = "";
    int ad = 0;
    for (int i = len - 1; i >= 0; i--)
    {
        if (str[i] - '0' + str1[i] - '0' + ad >= 10)
        {
            s += to_string(str[i] - '0' + str1[i] - '0' + ad - 10);
            ad = 1;
        }
        else
        {
            s += to_string(str[i] - '0' + str1[i] - '0' + ad);
            ad = 0;   
        }
    }
    if (ad == 1)
    {
        s += "1";
    }   
    reverse(s.begin(), s.end());
    return s;
}

int main(int argc, char const *argv[])
{
    string str, str1, str2;
    int a, b, c, flag = 0;
    cin >> str;
    if (ispal((str)))
    {
        cout << str << " is a palindromic number.";
        return 0;
    }
    for (int i = 0; i < 10; i++)
    {
        str1 = str;
        cout << str << " + ";
        reverse(str.begin(), str.end());
        str2 = add(str, str1);
        cout << str << " = " << str2 << endl;
        if (ispal(str2))
        {
            flag = 1;
            cout << str2 << " is a palindromic number.";
            return 0;
        }
        else
            str = str2;
    }
    if (flag == 0)
        cout << "Not found in 10 iterations.";
    return 0;
}
