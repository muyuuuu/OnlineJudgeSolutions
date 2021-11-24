- [树](#树)
  - [剑指 Offer 26. 树的子结构](#剑指-offer-26-树的子结构)
  - [剑指 Offer 27. 二叉树的镜像](#剑指-offer-27-二叉树的镜像)

# 树

用一句话总结，树能很好的考验算法设计能力和递归理解能力。

## 剑指 Offer 26. 树的子结构

输入两棵二叉树A和B，判断B是不是A的子结构。(约定空树不是任意一个树的子结构)。B是A的子结构， 即 A中有出现和B相同的结构和节点值。

一点一点来分析题目：首先在 A 和 B 中进行查找，如果不满足，就查找 A 的左子树或右子树，这样，递归的思想就出来了。查找函数是题目给定的，只需要递归调用题目的查找函数即可，需要注意的是，如果 A 的子树或者 B 的为空，返回 false，表示 B 为空树或者 A 中没有找到。

那么如何衡量有没有找到呢？就需要在写一个查找函数：

- B 为空，表示 B 被遍历完毕，返回 true
- A 为空，表示没找到，返回 false
- A B 不空的情况下数值不等，返回 false
- 否则表示 A 和 B 当前节点相等，继续比较 A 的左子树和 B 的左子树，A 的右子树和 B 的右子树

```cpp
class Solution {
public:
  bool isSubStructure(TreeNode* A, TreeNode* B) {
    if (B == nullptr)
      return false;
    if (A == nullptr)
      return false;
    bool a = dfs(A, B);
    bool b = isSubStructure(A->left, B);
    bool c = isSubStructure(A->right, B);
    return a || b || c;
  }

  bool dfs(TreeNode* A, TreeNode* B) {
    if (B == nullptr)
      return true;
    if (A == nullptr)
      return false;
    if (A->val != B->val)
      return false;
    return dfs(A->left, B->left) && dfs(A->right, B->right);
  }
};
```

## 剑指 Offer 27. 二叉树的镜像

请完成一个函数，输入一个二叉树，该函数输出它的镜像。

刚开始想的是从二叉树的底层开始镜像反转，发现无法实现。后来冷静分析下，发现从二叉树的根开始反转也是可以的。同样还是递归解决的思想，反转一个节点，而后反转它的子节点，递归即可。

```cpp
class Solution {
public:
  TreeNode* mirrorTree(TreeNode* root) {
    reverse(root);
    return root;
  }
  void reverse(TreeNode* root) {
    if (root == NULL)
      return;
    TreeNode* tmp;
    tmp = root->left;
    root->left = root->right;
    root->right = tmp;
    reverse(root->left);
    reverse(root->right);
  }
};
```