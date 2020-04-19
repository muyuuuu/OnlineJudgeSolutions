#include <iostream>
#include <vector>

using namespace std;

struct node
{
    int index = -1;
    int left = -1;
    int right = -1;
    int child = 0;
}arr[2500];

int n, root, temp[25], maxdepth = -1;
int ans[5] = {1, 2, 4, 8, 16};
vector<int> level[25];

void dfs(int index, int depth)
{
    if (depth > maxdepth)
        maxdepth = depth;
    level[depth].push_back(index);
    if (arr[index].left != -1)
        dfs(arr[index].left, depth + 1);
    if (arr[index].right != -1)
        dfs(arr[index].right, depth + 1);
}

int main(int argc, char const *argv[])
{
    cin >> n;
    string a, b;
    for (int i = 0; i < n; i++)
    {
        cin >> a >> b;
        arr[i].index = i;
        if (a != "-")
        {
            temp[stoi(a)] = 1;
            arr[i].left = stoi(a);
            arr[i].child ++;
        }
        if (b != "-")
        {
            arr[i].child ++;
            temp[stoi(b)] = 1;
            arr[i].right = stoi(b);
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (temp[i] == 0)
            root = i;
    }
    dfs(root, 0);
    if (maxdepth > 4)
    {
        cout << "NO " << root;
        return 0;
    }
    for (int i = 0; i < maxdepth; i++)
    {
        if (level[i].size() != ans[i])
        {
            cout << "NO " << root;
            return 0;
        }
    }
    int len = n;
    for (int i = 0; i < maxdepth; i++)
        len -= ans[i];
    int i = 0, flag = 0, flag1 = 0;
    // 判断最后一层是否满足要求
    // level[maxdepth - 1][i] 表示倒数第二层的节点索引号
    // arr[] 表示那个节点
    while (i < level[maxdepth - 1].size())
    {
        // 如果之前的节点不到两个孩子 而后面的节点有孩子
        if (flag == 1 && arr[level[maxdepth - 1][i]].child >= 1)
        {
            flag1 = 1;
            break;
        }
        // 只有一个节点且左孩子为空
        if (len == 1 && arr[level[maxdepth - 1][i]].left == -1)
        {
            flag1 = 1;
            break;
        }
        len -= arr[level[maxdepth - 1][i]].child;
        if (len <= 0) break;
        // 某个节点不足两个孩子
        if (arr[level[maxdepth - 1][i]].child != 2)
            flag = 1;
        i++;
    }
    // 增加96 97 98 三行代码会导致第六个测试点段错误
    if (flag1 == 1)
        cout << "NO " << root;
    else
        cout << "YES " << level[maxdepth][level[maxdepth].size() - 1];
    return 0;
}
