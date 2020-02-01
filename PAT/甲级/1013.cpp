s#include <iostream>
#include <algorithm>

using namespace std;

int adj[1010][1010];
bool visit[1010];
int n;

void dfs(int node) {
    visit[node] = true;
    for(int i = 1; i <= n; i++) {
        //  == 1 确保有这个节点
        if(visit[i] == false && adj[node][i] == 1)
            dfs(i);
    }
}

int main()
{
    int  m, k, a;
    cin >> n >> m >> k;
    int city1, city2;
    for (int i = 0; i < m; i++)
    {
        cin >> city1 >> city2;
        adj[city1][city2] = adj[city2][city1] = 1; 
    }
    for (int i = 0; i < k; i++)
    {
        // 所有节点设置为false，要求的节点设为 true
        // 孤立这个节点，看看有几个连通分量
        fill(visit, visit + 1010, false);
        scanf("%d", &a);
        int cnt = 0;
        visit[a] = true;
        // 如果一个节点没有被访问，就遍历
        // 然后和这个节点相邻的节点都为true，免得重复遍历
        for(int j = 1; j <= n; j++) {
            if(visit[j] == false) {
                dfs(j);
                // 记录连通子图的数量
                cnt++;
            }
        }
        // 连通分量 - 1，就是要修建的路数，变为连通图 
        printf("%d\n", cnt - 1);
    }
    return 0;
}