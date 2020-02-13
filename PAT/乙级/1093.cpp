#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    string str1, str2;
    getline(cin, str1);
    getline(cin, str2);
    string result = "";
    for (int i = 0; i < str1.length(); i++)
    {
        if (result.find(str1[i]) == string::npos)
        {
            result += str1[i];
        }
    }
    for (int i = 0; i < str2.length(); i++)
    {
        if (result.find(str2[i]) == string::npos)
        {
            result += str2[i];
        }
    }
    cout << result;
    return 0;
}
