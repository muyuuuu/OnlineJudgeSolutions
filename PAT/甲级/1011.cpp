#include <iostream>

using namespace std;

int main()
{
    char c[4] = {"WTL"};
    double a;
    double ans = 1.0;
    for (int i = 0; i < 3; i++)
    {
        double max = 0;
        int b = 0;
        for (int j = 0; j < 3; j++)
        {
            cin >> a;
            if (a >= max)
            {
                max = a;
                b = j;
            }
        }   
        ans = ans * max;
        cout << c[b] << " ";
    }
    printf("%.2f", (ans * 0.65 - 1 )*2);
    return 0;
}