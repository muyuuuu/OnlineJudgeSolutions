#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

// 初始化问题
vector<int> v[105];
int gene[105];
int n;

void dfs(int index, int depth)
{
    gene[depth]++;
    for (int i = 0; i < v[index].size(); i++)
    {
        dfs(v[index][i], depth+1); 
    }
}

int main()
{
    int  m;
    cin >> n >> m;
    int temp;
    int cnt;
    int temp1;
    for (int i = 0; i < m; i++)
    {
        cin >> temp >> cnt;
        for (int j = 0; j < cnt; j++)
        {
            cin >> temp1;
            v[temp].push_back(temp1);
        }
    }
    dfs(1, 1);
    int max = -1, maxn = 1;
    for (int i = 0; i < 105; i++)
    {
        if (gene[i] > max)
        {
            max = gene[i];
            maxn = i;
        }
    }
    cout << max << " " << maxn ;
    return 0;
}