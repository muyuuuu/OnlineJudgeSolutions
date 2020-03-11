#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    int n, key = 0, len = 0, len2 = 0;
    cin >> n;
    string str, temp = "", result = "";
    cin.get();
    for (int i = 0; i < n; i++)
    {
        getline(cin, str);
        if (temp == "")
        {
            temp = str;
            result = str;
            continue;
        }
        len2 = result.length();
        len = str.length();
        if (result[len2 - 1] != str[len - 1])
        {
            cout << "nai";
            return 0;
        }
        else
        {
            temp = result;
            int len1 = temp.length();
            while ((temp[len1 - 1 - key] == str[len - 1 - key]) && (len1 - 1 - key >= 0) && (len - 1 - key >= 0))
                key++;
            result = temp.substr(len1 - key, key);
            key = 0;
        }
    }
    for (int i = 0; i < result.length(); i++)
        cout << result[i];
    return 0;
}
