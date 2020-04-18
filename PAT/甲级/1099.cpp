#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct node
{
    int index = -2;
    int left = -2;
    int right = -2;
}arr[102];

vector<int> level[102], ans[102];
int arr1[102], n, t = 0, flag = 0;

void build(int idx)
{
    if (idx > n)
        return;
    if (arr[idx].left != -1)
        build(arr[idx].left);
    ans[idx].push_back(arr1[t++]);
    if (arr[idx].right != -1)
        build(arr[idx].right);
}

void dfs(int idx, int depth)
{
    if (idx > n)
        return;
    if (arr[idx].index == -2)
        return;
    if (ans[idx].size() == 0) 
        return;
    level[depth].push_back(ans[idx][0]);
    // 按照树的结构遍历
    if (arr[idx].left != -1)
        dfs(arr[idx].left, depth + 1);
    if (arr[idx].right != -1)
        dfs(arr[idx].right, depth + 1);
}

int main(int argc, char const *argv[])
{
    int a, b;
    cin >> n;   
    for (int i = 0; i < n; i++)
    {
        arr[i].index = i;
        cin >> a >> b;
        arr[i].left = a;
        arr[i].right = b;
    }
    for (int i = 0; i < n; i++)
        cin >> arr1[i];
    sort(arr1 + 0, arr1 + n);
    build(0);
    dfs(0, 0);
    int flag = 0;
    for (int i = 0; i < n; i++)
        if (level[i].size() != 0)   
            for (int j = 0; j < level[i].size(); j++)
            {
                if (flag == 0)
                {
                    flag = 1;
                    cout << level[i][j];
                }
                else
                    cout << " " << level[i][j];
            }
    return 0;
}
