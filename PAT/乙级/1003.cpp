#include <iostream>

using namespace std;

int main()
{
    int a;
    cin >> a;
    string str;
    for (int i = 0; i < a; i++)
    {
        cin >> str;
        if (str[0] == 'P')
        {
            int p_num = 0; int a_num = 0; int t_num = 0;
            for (int j = 0; j < str.length(); j++)
            {
                if (str[j] == 'A')
                {
                    a_num = 1;
                }
                if (str[j] == 'T' && a_num == 1)
                {
                    t_num = 1;
                }
            }
            if (a_num == 1 && t_num == 1)
            {
                cout << "Yes" << endl;
                continue;
            }
        }
        else if (str[0] == 'A')
        {
            
        }
        else
        {
            cout << "No" << endl;
            continue;
        }
        
    }
    return 0;
}