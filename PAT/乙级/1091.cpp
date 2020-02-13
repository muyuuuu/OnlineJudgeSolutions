#include <iostream>

using namespace std;

int arr[22];

int main(int argc, char const *argv[])
{
    int m;
    cin >> m;
    int result, flag = 0;
    string str, str1;
    for (int i = 0; i < m; i++)
        cin >> arr[i];
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            result = j * arr[i] * arr[i];
            str = to_string(result);
            str1 = to_string(arr[i]);
            for (int k = str1.length() - 1; k >= 0; k--)
            {
                if (str1[k] != str[str.length() - str1.length() + k])
                    flag = 1;
            }     
            if (flag == 0)
            {
                cout << j << " " << result << endl;
                break;
            }
            if (j == 9 && flag == 1)
            {
                cout << "No" << endl;
                break;
            }
            flag = 0;
        }
    }
    return 0;
}
