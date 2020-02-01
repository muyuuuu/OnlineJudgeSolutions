#include <iostream>
#include <vector>

using namespace std;

vector<int> v[100];
int book[100] = {0}; 
int maxdepth = -1;

void dfs(int index, int depth)
{
	// 只有一个节点，叶子节点数 ++
	if (v[index].size() == 0)
	{
		// 这一层的孩子数 ++ 
		book[depth]++;
		maxdepth = max(depth, maxdepth);
		return;
	}
	// 如果有孩子，层次递归遍历
	for (int i = 0; i < v[index].size(); ++i)
	{
		// v[index][i] 是一个 整数，
		// 传进去就是第几号叶子节点
		// 如果有孩子，就继续这个循环，
		// 向下递增，所以是深度优先
		dfs(v[index][i], depth+1);
	}
}

int main(int argc, char const *argv[])
{
	int N, M;
	int node, num, node1;
	scanf("%d %d", &N, &M);
	for (int i = 0; i < M; ++i)
	{
		scanf("%d %d", &node, &num);
		for (int j = 0; j < num; ++j)
		{
			scanf("%d", &node1);
			// 存入一个节点的孩子 
			// 注意这是一个二维不定长数组
			v[node].push_back(node1);
		}
	}
	// 根节点是1，深度是0，从根节点开始遍历
	dfs(1, 0);
	printf("%d", book[0]);
	for(int i = 1; i <= maxdepth; i++)
        printf(" %d", book[i]);
	return 0;
}