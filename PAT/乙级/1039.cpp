#include <iostream>

using namespace std;

int main()
{
    string str, str1;
    cin >> str >> str1;
    int flag = 1;
    int count = 0;
    int length = str.length();
    for (int i = 0; i < str1.length(); i++)
    {
        int pos = str.find_first_of(str1[i]);
        if (pos != -1)
        {
            str.replace(pos, 1, "#");
        }
        else
        {
            flag = 0;
            count++;
        }   
    }
    if (flag == 1)
    {
        cout << "Yes " << length - str1.length();
        return 0;
    }
    else
    {
        cout << "No " << count;
    }
    return 0;
}