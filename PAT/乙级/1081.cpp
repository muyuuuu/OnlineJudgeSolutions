#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    string temp;
    cin.get();
    int digit = 0, alpha = 0, flag = 0;
    for (int i = 0; i < n; i++)
    {
        getline(cin , temp);
        if (temp.length() < 6)
        {
            flag = 1;
            cout << "Your password is tai duan le." << endl;
        }
        else
        {
            for (int j = 0; j < temp.length(); j++)
            {
                if (isdigit(temp[j]) || isalpha(temp[j]) || temp[j] == '.')
                {
                    if (isdigit(temp[j]))
                        digit = 1;
                    if (isalpha(temp[j]))
                        alpha = 1;
                }
                else
                {
                    if (flag == 0)
                        cout << "Your password is tai luan le." << endl;
                    flag = 1;
                    break;
                }
            }
            if (digit == 0 && alpha == 0 && flag == 0)
            {
                flag = 1;
                cout << "Your password is tai luan le." << endl;
            }
            if (digit == 0 && alpha == 1 && flag == 0)
            {
                cout << "Your password needs shu zi." << endl;
                flag = 1;
            }
            if (alpha == 0 && digit == 1 && flag == 0)
            {
                cout << "Your password needs zi mu." << endl;
                flag = 1;
            }
            if (flag == 0 && alpha == 1 && digit == 1)
            {
                cout << "Your password is wan mei." << endl;
            }
        }
        flag = 0; digit = 0; alpha = 0;
    }
    return 0;
}