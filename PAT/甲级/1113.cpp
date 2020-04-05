#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> v;

int main(int argc, char const *argv[])
{
    int n, a, sum1 = 0, sum2 = 0;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a;
        v.push_back(a);
    }
    sort(v.begin(), v.end());
    if (n % 2 == 0)
    {
        for (int i = 0; i <= n / 2 - 1; i++)
            sum1 += v[i];
        for (int i = n / 2; i < n; i++)
            sum2 += v[i];
        cout << "0 " << sum2 - sum1;
    }
    else
    {
        for (int i = 0; i <= (n - 1) / 2 - 1; i++)
            sum1 += v[i];
        for (int i = (n - 1) / 2; i < n; i++)
            sum2 += v[i];
        cout << "1 " << sum2 - sum1;   
    }
    return 0;
}
