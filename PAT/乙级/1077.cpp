#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> v;

int main(int argc, char const *argv[])
{
    int m, n, temp;
    cin >> n >> m;
    int key = 0, sum = 0;
    float average;
    v.resize(0);
    for (int j = 0; j < n; j++)
    {
        for (int i = 0; i < n; i++)
        {
            cin >> temp;
            if (temp >= 0 && temp <= m)
            {
                v.push_back(temp);
            }
        }
        sort(v.begin() + 1, v.end());
        for (int i = 2; i < v.size() - 1; i++)
        {
            sum += v[i];
            key++;
        }
        average = sum/key;
        // cout << sum << "--" << key << "--";
        average = (average + v[0]) / 2;
        cout << (int)(average+0.5) << endl;
        v.resize(0);
        sum = 0;
        key = 0;
    }
    return 0;
}
