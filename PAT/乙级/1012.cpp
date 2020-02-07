#include <iostream>

using namespace std;

int main()
{
    int temp;
    int a1 = 0, a2 = 0, a3 = 0;
    float a4 = 0;
    int flag = 1;
    int a5 = -10;
    int a4_count = 0;
    int n;
    cin >> n;
    int a1_flag = 0, a2_flag = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> temp;
        if (temp % 5 == 0 && temp % 2 == 0)
        {
            a1 += temp;
            a1_flag = 1;
            continue;
        }
        if (temp % 5 == 1)
        {
            a2 = a2 + temp * flag;
            a2_flag = 1;
            flag = flag * (-1);
            continue;
        }
        if (temp % 5 == 2)
        {
            a3 ++;
            continue;
        }
        if (temp % 5 == 3)
        {
            a4 += temp;
            // cout << temp << endl;
            a4_count++;
            continue;
        }
        if (temp % 5 == 4)
        {
            if (temp > a5)
                a5 = temp;
        }
    }
    a1_flag==0?cout << "N " : cout << a1 << " ";
    a2_flag==0?cout << "N " : cout << a2 << " ";
    a3==0?cout << "N " : cout << a3 << " ";
    a4_count==0?printf("N "): printf("%.1f ", a4/a4_count);
    a5==-10?cout << "N" : cout << a5;
    return 0;
}