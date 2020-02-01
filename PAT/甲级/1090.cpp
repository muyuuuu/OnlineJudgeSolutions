#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

vector<int> v[100005];

int maxdepth = -1, maxnum = 0;

void dfs(int index, int depth)
{
    // if (v[index].size() == 0)
    // {
        if (depth == maxdepth)
        {
            maxnum++;
        }
        if (depth > maxdepth)
        {
            maxdepth = depth;
            maxnum = 1;
        }
        for (int i = 0; i < v[index].size(); i++)
        {
            dfs(v[index][i], depth + 1);
        }
    // }
}


int main()
{
    int n;
    double p, r;
    cin >> n >> p >> r;
    r = r / 100;
    int temp;
    int root;
    for (int i = 0; i < n; i++)
    {
        cin >> temp;
        if (temp == -1)
            root = i;
        else
            v[temp].push_back(i);
    }
    dfs(root, 0);
    printf("%0.2f %d", p * pow(1+r, maxdepth), maxnum);
    return 0;
}