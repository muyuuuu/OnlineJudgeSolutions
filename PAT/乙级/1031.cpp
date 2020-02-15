#include <iostream>

using namespace std;

int weight[17] = {7, 9, 10, 5, 8, 4, 2, 1, 6, 3, 7, 9, 10, 5, 8, 4, 2};
char check[11] = {'1', '0', 'X', '9', '8', '7', '6', '5', '4', '3', '2'};

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    string str;
    int count = 0, sum = 0;
    int flag = 0;
    if (n == 0)
    {
        return 0;
    }
    for (int i = 0; i < n; i++)
    {
        cin >> str;
        sum = 0;
        flag = 0;
        if (str.length() != 18)
        {
            count++;
            cout << str << endl;
            continue;
        }
        for (int j = 0; j < 17; j++)
        {
            if (isdigit(str[j]))
            {
                sum += (str[j] - '0') * weight[j];
            }
            else
            {
                count++;
                flag = 1;
                cout << str << endl;
                break;
            }
        }
        if (flag == 0)
        {
            sum = sum % 11;
            if (str[17] != check[sum])
            {
                count++;
                cout << str << endl;
            }
        }
    }
    if (count == 0)
    {
        cout << "All passed";
    }
    return 0;
}
