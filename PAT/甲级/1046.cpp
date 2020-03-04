#include <iostream>
#include <algorithm>

using namespace std;

int dis[100005];

int main(int argc, char const *argv[])
{
    int n, m, a, b, sum = 0, temp;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> temp;
        sum += temp;
        dis[i] = sum;
    }
    scanf("%d", &m);
    int dis1 = 0, dis2 = 0;
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b;
        if (a > b)
            swap(a, b);
        dis1 = dis[b - 1] - dis[a - 1];
        dis2 = sum - dis1;
        dis1 < dis2 ? printf("%d\n", dis1) : printf("%d\n", dis2);
        dis1 = 0;
        dis2 = 0;
    }
    return 0;
}
