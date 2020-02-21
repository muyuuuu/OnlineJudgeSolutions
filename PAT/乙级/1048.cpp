#include <iostream>
#include <algorithm>

using namespace std;
// 13212132 21
int main(int argc, char const *argv[])
{
    string str, str1, result;
    cin >> str >> str1;
    int key = 0;
    int count = 0, count1 = 0;
    int len1 = str1.length();
    char temp[14] = {"0123456789JQK"};

    if (str1.length() > str.length())
        count = str1.length() - str.length();
        
    if (str.length() > str1.length())
        for (int i = 0; i < str.length() - len1; i++)
            str1.insert(0, "0");
            
    int len = str.length() > str1.length() ? str1.length() : str.length();

    for (int i = len - 1; i >= 0; i--)
    {
        if (key == 0)
            result += temp[(str[i + count1] - '0' + str1[i + count] - '0') % 13];
        if (key == 1)
        {
            if (str1[i + count] - '0' - str[i + count1] + '0' < 0)
                result += to_string(str1[i + count] - '0' - str[i + count1] + '0' + 10);
            else
                result += to_string(str1[i + count] - '0' - str[i + count1] + '0');
        }
        key = (key == 0 ? 1 : 0);
    }
    if (str.length() < str1.length())
        for (int i = str1.length() - str.length() - 1; i >= 0; i --)
            result += str1[i];
    reverse(result.begin(), result.end());
    cout << result;
    return 0;
}
