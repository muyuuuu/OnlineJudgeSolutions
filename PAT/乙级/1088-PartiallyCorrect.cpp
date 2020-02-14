#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

struct node
{
    float x;
    float y;
};

vector<node> v;

bool cmp(node &a, node &b)
{
    return a.x > b.x;
}

int main(int argc, char const *argv[])
{
    float m, x, y;
    cin >> m >> x >> y;
    int flag = 0;
    node temp;
    v.resize(0);
    for (float i = 0; i < 10; i++)
    {
        for (float j = 0; j <= 9; j++)
        {
            if ( abs(9*i - 9*j) / x == (10*j + i) / y )
            {
                if (10*j + i != 0)
                {
                    flag = 1;
                    temp.x = i;
                    temp.y = j;
                    v.push_back(temp);
                }
            }
        }
    }
    if (flag == 0)
    {
        cout << "No Solution";
    }
    else
    {
        sort(v.begin(), v.end(), cmp);
        int a[3];
        a[0] = 10 * v[0].x + v[0].y;
        a[1] = 10 * v[0].y + v[0].x;
        a[2] = a[1] / y;
        if (a[0] <= 10)
        {
            cout << "No Solution";
            return 0;
        }
        cout << a[0];
        for (int i = 0; i < 3; i++)
        {
            if (m > a[i]) cout << " Gai";
            if (m == a[i]) cout << " Ping";
            if (m < a[i]) cout << " Cong";
        }
    }
    return 0;
}
