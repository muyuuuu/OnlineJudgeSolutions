#include <iostream>
#include <vector>

using namespace std;

struct node
{
    int left = -1;
    int right = -1;
    int flag = 0;
}arr[12];

vector <int> v[12], book[12];
int arr1[12], root, flag1 = 0;

// 层次遍历
void dfs(int index, int depth)
{
    book[depth].push_back(index);
    if (v[index].size() == 0)
        return;
    for (int i = 0; i < v[index].size(); i++)
    {
        dfs(v[index][i], depth + 1);
    }
}

// 右 根 左的遍历顺序
void dfs1(int index)
{
    // 一直访问右节点
    if (arr[index].right != -1)
        dfs1(arr[index].right);
    // 输出右子树
    if (arr[index].right == -1)
    {
        if (flag1 == 0)
        {
            cout << index;
            flag1 = 1;
        }
        else
            cout << " " << index;
        arr[index].flag = 1;
    }
    // 输出根节点
    else if (arr[arr[index].right].flag == 1)
    {
        cout << " " << index;
        arr[index].flag = 1;
    }
    // 输出左节点
    else if (arr[index].left == -1 && arr[index].right == -1)
    {
        cout << " " << index;
        return;
    }
    // 最后访问左子树
    if (arr[index].left != -1)
        dfs1(arr[index].left);
}

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    char a, b;
    for (int i = 0; i < n; i++)
    {
        cin >> a >> b;
        // 先访问右孩子
        if (b != '-') 
        {
            v[i].push_back(b - '0');
            arr[i].right = b - '0';
            // cout << arr[i].right << "!!!!!!!!" << endl;
            arr1[b - '0'] = 2;
        }
        if (a != '-') 
        {
            v[i].push_back(a - '0');
            arr[i].left = a - '0';
            arr1[a - '0'] = 2;
        }
    }
    for (int i = 0; i < n; i++)
        if (arr1[i] != 2)
            root = i;
    dfs(root, 0);
    int flag = 0;
    for (int i = 0; i < 12; i ++)
    {
        if (book[i].size() != 0)
        {
            for (int j = 0; j < book[i].size(); j++)
            {
                if (flag == 0)
                {
                    cout << book[i][j];
                    flag = 1;
                }
                else
                    cout << " " << book[i][j];
            }
        }
    }
    cout << endl;
    dfs1(root);
    // for (int i = 0; i < n; i++)
    //     cout << arr[i].right << " " << arr[i].left << " ";
    // return 0;
}
