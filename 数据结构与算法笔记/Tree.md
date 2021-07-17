# 树

## 建立二叉搜索树

这里只涉及最基本的二叉树的建立与 `dfs` 遍历。

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

- 建立二叉树，指明左子树和右子树的根节点的地址，使用 `new` 使地址生效；
- 遍历时，按照深度，记录每一层的节点数。

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

第一行的 $N$ 是元素数量，之后的 $N$ 行，当前行的索引表示当前节点的索引，每一行的第一个元素是当前节点左孩子的索引，第二个元素是当前节点右孩子的索引，以此指明了树的结构。最后一行是要插入到当前树结构的元素，最后层序遍历输出。

#### sample input

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

- 首先使用结构体和向量记录树的结构
- **而后对要插入的数据进行排序**
- 之后构建树并进行遍历。构建的过程需要注意，对树的节点进行编号，记录每个编号要存储的值。
- 因为这是二叉树，所以，沿着树的结构一直访问左子树，而后对左子树赋值，赋值元素依次为排序数组，这样保证树是可查找的。
- 层序遍历，仍然按照高度记录元素。从左到右还是从右到左，依赖题目描述。

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
int arr[105], n{0}, cnt{0}, max_depth{-10};
// arr1 记录树的结构
node arr1[105];
// res 记录树节点的取值
// level 记录层序遍历
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

## 完全二叉搜索树

建立的二叉树是完全树的结构。

#### sample in

```
10
1 2 3 4 5 6 7 8 9 0
```

#### sample out

```
6 3 8 1 5 7 9 0 2 4
```

### code

- 这个题目的思路和上一个很像，首先对二叉树进行编号，根节点是 0，左孩子是 1，右孩子是 2 这样，来记录每个树节点应该存储那个数值。用数组来实现，数组的下标是树节点的编号，元素是当前节点的取值。
- 所以要对数组元素进行排序。遍历的时候，一直遍历左子树。当不能遍历下去的时候，对当前节点按照排序数组依次赋值。

```cpp
#include <iostream>
#include <algorithm>

using namespace std;

int arr[1010], level[1010], n, t{0};

void dfs(int root) {
    if (root >= n)
        return;
    dfs(root * 2 + 1);
    // 如果遍历不下去，当前元素设置最小值
    level[root] = arr[t++];
    dfs(root * 2 + 2);
}

int main (){

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    sort(arr, arr + n);
    dfs(0);
    cout << level[0];
    // 层序遍历
    for (int i = 1; i < n; i++)
        printf(" %d", level[i]);
}
```