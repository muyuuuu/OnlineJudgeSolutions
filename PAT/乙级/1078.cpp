#include <iostream>

using namespace std;

int main()
{
    char flag;
    cin >> flag;
    cin.get();
    string str;
    getline(cin, str);
    // 压缩
    if (flag == 'C')
    {
        int cnt = 1;
        char a, b;
        for (int i = 0; i < str.size() ; i++)
        {
            a = str[i];
            b = str[i+1];
            if (a == b)
            {
                cnt++;
                continue;
            }
            if (a != b)
            {
                if (cnt == 1)
                    cout << a;
                else
                    cout << cnt << a;
                cnt = 1;
            }      
        }
    }
    // 解压
    if (flag == 'D')
    {
        string num;
        for (int i = 0; i < str.size(); i++)
        {
            if ( str[i] >= '0' && str[i] <= '9')
            {
                num += str[i];
            }
            else if (num.size() > 0)
            {
                for (int j = 0; j < stoi(num); j++)
                    cout << str[i];
                num = "";
            }
            else
            {
                cout << str[i];
            }
        }
    }
    return 0;
}