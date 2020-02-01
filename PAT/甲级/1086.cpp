#include <iostream>
#include <vector>
#include <stack>
#include <cstring>

using namespace std;

vector<int> pre, in, post,value;

void postorder(int root, int start, int end) {
    if (start > end) return;
    // i 从开始节点（最左的左子树）
    int i = start;
    // 寻找到当前子树的根节点, 以 i 表示
    // 则中序遍历的 in 中，小于 i 全是左子树，大于i全是右子树，递归即可
    while (i < end && in[i] != pre[root]) 
        i++;
    // 递归左子树，根节点就是pre下移一位，从start搜索到 i-1
    postorder(root + 1, start, i - 1);
    // 递归右子树，记上次的根节点为 j
    // 则 start = j + 1
    // 根节点的表示为：root + 1 + i - 1 - j = root + i - j;
    // 含义为：i - j 是 新根与旧根的距离，root 加上这个距离会到新根的位置
    postorder(root + 1 + i - start, i + 1, end);
    // 访问根，就是后序遍历的常规操作了
    post.push_back(root);
    // post.push_back(pre[root]);
    // 上面注释掉的是好的写法，直接对应到值或索引，因为并不是所有的 root 都从零开始
    // root 找到了根的索引，只有先序的索引和值的索引是对应的
    // 4 号索引应该对应 4 号值 
    // 用 pre[root]会得到后序顺序对应的 value 值，中序 in[root] 这个索引并不是对应 value[]位置的值
    // 所以使用先序，而不是中序
}

int main() {
    int n;
    scanf("%d", &n);
    char str[5];
    stack<int> s;
    int key=0;
    while (~scanf("%s", str)) {
        if (strlen(str) == 4) {
            int num;
            scanf("%d", &num);
            // 先序的顺序存储 树的 数值
            // 按顺序输出就是后序遍历的数值
            value.push_back(num);
            // 先序的顺序，会和后序对应
            // 后序也是存储的节点的索引，只是和先序的顺序不一样
            pre.push_back(key);
            // s 是辅助存储中序遍历的 顺序
            s.push(key++);
        } else {
            // 每次pop，都是中序的访问顺序
            in.push_back(s.top());
            s.pop();
        }
    }
    // 开始后序遍历，0在先序遍历中是根节点，0是开始节点，总共的节点数是 n - 1
    postorder(0, 0, n - 1);
    printf("%d", value[post[0]]);
    for (int i = 1; i < n; i++)
        printf(" %d",value[post[i]]);
    return 0;
}