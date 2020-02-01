#include <iostream>

using namespace std;

double b[100005];

int main()
{
    int n;
    cin >> n;
    double sum = 0.0;
    // cout << n;
    string str;
    cin.get();
    getline(cin, str);
    // cout << str.length();
    int key = 0;
    for (int i = 1; i < str.length(); i++)
    {
        if (str[i] - '0' >= 0 && str[i] - '9' <= 0 && str[i - 1] == '.')
        {
            // cout << str[i];   
            b[key++] = (str[i] - '0');
        }
    }
    for (int i = 0; i < key; i++)
    {
        b[i] = b[i] / 10;
    }
    for (int i = 0; i < key; i++)
    {
        double temp1 = 0;
        for (int j = i; j < key; j++)
        {
            for (int k = i; k < j; k++)
            {
                temp1 += b[k];
            }
            temp1 += b[j];
        }
        sum += temp1;
    }
    printf("%.2f", sum);
    return 0;
}