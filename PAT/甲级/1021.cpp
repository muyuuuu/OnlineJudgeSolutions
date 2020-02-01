#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

int n;
int adj[10004][10004] = {0};
bool visit[10004] = {false};
int max_height = -1;
vector<int> v;
set<int> s;

void dfs(int node, int height)
{
    visit[node] = true;
    if (height > max_height)
    {
        v.clear();
        max_height = height;
        v.push_back(node);
    }
    if (height == max_height)
    {
        v.push_back(node);
    }
    for (int i = 1; i <= n; i++)
    {
        if (adj[node][i] == 1 && visit[i] == false)
            dfs(i, height + 1);
    }
}

int main()
{
    cin >> n;
    int a, b;
    for (int i = 1; i < n; i++)
    {
        cin >> a >> b;
        adj[a][b] = adj[b][a] = 1;
    }
    fill(visit, visit + 10004, false);
    int cnt = 0;
    for (int i = 1; i <= n; i++)
    {
        if (visit[i] == false)
        {
            dfs(i, 1);
            cnt++;
            if(i == 1) 
            {
                for(int j = 0; j < v.size(); j++)
                    s.insert(v[j]);
            }
        }
    }
    if (cnt != 1)
    {
        cout << "Error: " << cnt << " components";
        return 0;
    }
    else
    {
        int root = v[0];
        v.clear();
        max_height = -1;
        fill(visit, visit + 10004, false);
        dfs(root, 1);
    }
    for(int i = 0; i < v.size(); i++)
        s.insert(v[i]);
    for(auto it = s.begin(); it != s.end(); it++)
        printf("%d\n", *it);
    return 0;
}