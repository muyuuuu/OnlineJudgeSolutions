#include <iostream>
#include <vector>

using namespace std;

int main()
{
    string str1, str2;
    getline(cin, str1);
    getline(cin, str2);
    bool flag[256] = {false};
    for (int i = 0; i < str1.length(); i++)
        flag[str1[i]] = true;
    for (int i = 0; i < str2.length(); i++)
        flag[str2[i]] = false;
    for (int i = 0; i < str1.length(); i++)
    {
        if (flag[str1[i]] == true)
            printf("%c", str1[i]);
    }  
    return 0;
}