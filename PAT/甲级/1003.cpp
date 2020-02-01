#include <iostream>
#include <algorithm>

using namespace std;

#define maxn 510
const int inf = 99999999;

int main()
{
	int n, m, c1, c2;
	int edge[maxn][maxn];
	int weight[maxn];
	int w[maxn];
	int dis[maxn];
	int num[maxn];
	bool visit[maxn];
	
	scanf("%d%d%d%d", &n, &m, &c1, &c2);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &weight[i]);
	}
	fill(edge[0], edge[0] + maxn * maxn, inf);
	fill(dis, dis + maxn, inf);
	int a=0, b=0, c=0;
	for (int i = 0; i < m; i++)
	{
		scanf("%d%d%d", &a, &b, &c);
		edge[a][b] = edge[b][a] = c;	
	}
	dis[c1] = 0;
	num[c1] = 1;
	w[c1] = weight[c1];
	for(int i = 0; i < n; i++)
	{
		int u = -1, minn = inf;
		for (int j = 0; j < n; j++)
		{
			if (visit[j] == false && dis[j] < minn)
			{
				u = j;
				minn = dis[j];
			}
		}
		if (u == -1)
			break;
		visit[u] = true;
		for (int v = 0; v < n; v++)
		{
			if (visit[v] == false && edge[u][v] != inf)
			{
				if(dis[u] + edge[u][v] < dis[v])
				{
					dis[v] = dis[u] + edge[u][v];
					num[v] = num[u];
					w[v] = w[u] + weight[v];
					// cout<<v<<" one "<<w[v]<<endl;
				}
				else if (dis[u] + edge[u][v] == dis[v])
				{
					num[v] = num[v] + num[u];
					// 相等的话只派送一次即可
					if (w[u] + weight[v] > w[v])
					{
						w[v] = w[u] + weight[v];
						// cout<<w[u]<<" two "<<w[v]<<endl;
					}		
					if (w[u] + weight[v] < w[v])
					{
						cout<<"yes"<<endl;
					}
				}
			}
		}
	}
	printf("%d %d", num[c2], w[c2]);
	return 0; 
} 