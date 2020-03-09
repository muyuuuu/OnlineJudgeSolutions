#include <iostream>
#include <cmath>

using namespace std;

int main(int argc, char const *argv[])
{
    long int left = 0, len = 0, n, max;
    cin >> n;
    max = sqrt(n);
    for (int i = 2; i <= max + 1; i++)
    {
        long int temp = 1;
        int j;
        // j 要等于 i ，因为有 2 * 2 = 4 的情况 
        for (j = i; j <= max + 1; j++)
        {
            temp *= j;
            if (n % temp != 0) break;
        }
        // 子串的数量最大
        if (j - i > len)
        {
            len = j - i;
            left = i;
        }
    }
    if (left == 0)
        cout << 1 << endl << n;
    else
    {
        cout << len << endl;
        for (int i = left; i < left + len; i++)
            i == left ? cout << i : cout << "*" << i;
    }
    return 0;
}