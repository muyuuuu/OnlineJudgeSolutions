# 树

## 建立二叉搜索树

#### sample input

第一行是元素数量，第二行是需要被插入的元素。求出树的最后一层和倒数第二层共有几个元素。

```
9
25 30 42 16 20 20 35 -5 28
```

#### sample output

```
2 + 4 = 6
```

### code

```cpp
#include <iostream>

using namespace std;

struct node {
    int v;
    struct node* left;
    struct node* right;
};
int maxdepth = -1;
int num[1000] = {0};

node* build (node* root, int v) {
    if (root == nullptr) {
        root = new node();
        root->v = v;
        root->left = nullptr;
        root->right = nullptr;
    }
    else if (root->v >= v) {
        root->left = build(root->left, v);
    }
    else {
        root->right = build(root->right, v);
    }
    return root;
}

void dfs(node *root, int depth)
{
    if (root == NULL) {
        if (depth > maxdepth)
            maxdepth = depth;
        return;
    }
    num[depth]++;
    dfs(root->left, depth+1);
    dfs(root->right, depth+1);
}

int main (){

    int n, t;
    cin >> n;
    node* root = nullptr;
    for (int i = 0; i < n; i++) {
        cin >> t;
        root = build(root, t);
    }
    dfs(root, 0);
    cout << num[maxdepth - 1] << " + " << num[maxdepth - 2] << " = " << num[maxdepth - 2] + num[maxdepth - 1];

    return 0;
}
```

## 按指定结构建立二叉搜索树

#### sample input

第一行的 $N$ 是元素数量，之后的 $N$ 行，索引表示当前节点的索引，第一个元素是当前节点左孩子的索引，第二个元素是当前节点右孩子的索引，指明了树的结构。最后一行是要插入到当前树的元素，最后层序遍历输出。

```
9
1 6
2 3
-1 -1
-1 4
5 -1
-1 -1
7 -1
-1 8
-1 -1
73 45 11 58 82 25 67 38 42
```

#### sample output

```
58 25 82 11 38 67 45 73 42
```

### code

```cpp
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct node {
    int l{-2};
    int r{-2};
};

// arr 记录排序后的数组
// arr1 记录树的结构
// res 记录树节点的取值
// level 记录层序遍历
int arr[105], n{0}, cnt{0}, max_depth{-10};
node arr1[105];
vector<int> level[105], res[105];

void build(int idx) {
    if (idx > n)
        return;
    if (arr1[idx].l != -1)
        build(arr1[idx].l);
    res[idx].push_back(arr[cnt++]);
    if (arr1[idx].r != -1)
        build(arr1[idx].r);
}

void dfs(int idx, int depth) {
    if (depth > max_depth)
        max_depth = depth;
    if (idx > n || res[idx].size() == 0)
        return ;
    level[depth].push_back(res[idx][0]);
    if (arr1[idx].l != -1)
        dfs(arr1[idx].l, depth+1);
    if (arr1[idx].r != -1)
        dfs(arr1[idx].r, depth+1);
}

int main (){

    int a, b;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        arr1[i].l = a;
        arr1[i].r = b;
    }
    for (int i = 0; i < n; i++) {
        cin >> a;
        arr[i] = a;
    }
    sort(arr, arr + n);
    build(0);
    dfs(0, 0);
    int flag = 0;
    for (int i = 0; i < n; i++)
        if (level[i].size() != 0)
            for (int j = 0; j < level[i].size(); j++) {
                if (flag == 0) {
                    flag = 1;
                    cout << level[i][j];
                }
                else
                    cout << " " << level[i][j];
            }
    return 0;
}
```