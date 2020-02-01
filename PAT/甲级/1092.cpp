#include <iostream>

using namespace std;

int main()
{
    string str1, str2;
    getline(cin, str1);
    getline(cin, str2);
    int flag[256] = {0};
    for (int i = 0; i < str1.size(); i++)
    {
        flag[str1[i]]++;
    }
    int temp = 0, num = 0;
    for (int i = 0; i < str2.size(); i++)
    {
        flag[str2[i]]--;
        if (flag[str2[i]] < 0)
        {
            temp = 1;
            num++;
        }
    }
    if (temp == 1)
    {
        cout << "No" << " " << num;
    }
    if (temp == 0)
    {
        cout << "Yes" << " " << str1.size() - str2.size();
    }
    return 0;
}