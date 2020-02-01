#include <iostream>
#include <vector>

using namespace std;

vector <int> v;

int main()
{
    int a, b;
    cin >> a;
    v.resize(a);
    for (int i = 0; i < a; i++)
    {
        cin >> b;
        v[i] = b;
    }
    // for (auto it = v.begin(); it != v.end(); it++)
    //     cout << *it;
    int sum = 0;
    for (int i = 0; i < a; i++)
    {
        if (i == 0)
        {
            sum += v[i] * 6;
            sum += 5;
        }
        else
        {
            if (v[i] > v[i-1])
            {
                sum += (v[i] - v[i - 1]) * 6;
                sum += 5;
            }
            if (v[i] < v[i-1])
            {
                sum += (v[i-1] - v[i]) * 4;
                sum += 5;
            }
            if (v[i] == v[i-1])
                sum += 5;
        }
    }
    cout << sum  ;
    return 0;
}