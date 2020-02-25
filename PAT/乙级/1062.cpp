#include <iostream>

using namespace std;

int gcd(int a, int b)
{
    return b == 0 ? a : gcd(b, a % b);
}

int main(int argc, char const *argv[])
{
    int k;
    float n1, m1, n2, m2;
    scanf("%f/%f %f/%f %d", &n1, &m1, &n2, &m2, &k);
    n1 = n1 / (m1 / k);
    n2 = n2 / (m2 / k);
    float max = n1 > n2 ? n1 : n2;
    float min = n1 < n2 ? n1 : n2;
    int flag = 0;
    for (int i = 1; i < max; i++)
    {
        if (i > min && gcd(i, k) == 1)
        {
            if (flag == 0)
            {
                printf("%d/%d", i, k);
                flag = 1;
            }
            else
                printf(" %d/%d", i, k);
        }
    }
    return 0;
}
