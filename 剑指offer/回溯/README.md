- [回溯](#回溯)
  - [剑指 Offer 12. 矩阵中的路径](#剑指-offer-12-矩阵中的路径)
  - [剑指 Offer 38. 字符串的排列](#剑指-offer-38-字符串的排列)
  - [剑指 Offer 34. 二叉树中和为某一值的路径](#剑指-offer-34-二叉树中和为某一值的路径)

# 回溯

回溯模板：

```
主函数：遍历所有条件
子函数：
    是否越界
    是否满足条件
    如果不满足
        追加
        递归调用
        回退
```

## 剑指 Offer 12. 矩阵中的路径

怎么说呢？回溯类的题目还是不熟悉，需要勤加练习。给定一个 m x n 二维字符网格 board 和一个字符串单词 word 。如果 word 存在于网格中，返回 true ；否则，返回 false 。

单词必须按照字母顺序，通过相邻的单元格内的字母构成，其中“相邻”单元格是那些水平相邻或垂直相邻的单元格。同一个单元格内的字母不允许被重复使用。例如，在下面的 3×4 的矩阵中包含单词 "ABCCED"（单词中的字母已标出）。

![](https://assets.leetcode.com/uploads/2020/11/04/word2.jpg)

我的想法很简单：因为矩阵的每个元素都可能是 `word` 的开头，因此只能暴力遍历。在遍历的时候：
1. 如果越界，返回 false
2. 如果满足条件，返回 true
3. 否则增加结果，递归调用回溯，而后回退
4. 为防止走回头路，使用 map 记录走过的路，这带来了空间的开销

```cpp
class Solution {
public:

  unordered_map<int, unordered_map<int, bool>> m1;
  int row;
  int col;

  bool exist(vector<vector<char>>& board, string word) {
    row = board.size(), col = board[0].size();
    if (row * col < word.size())
      return false; 
    string s;
    for (int i = 0; i < row; i++) {
      for (int j = 0; j < col; j++) {
        if (board[i][j] == word[0]) {
          if (word.size() == 1)
            return true;
          s = word[0];
          m1[i][j] = true;
          if (dfs(board, i + 1, j, 1, s, word))
            return true;
          if (dfs(board, i - 1, j, 1, s, word))
            return true;
          if (dfs(board, i, j + 1, 1, s, word))
            return true;
          if (dfs(board, i, j - 1, 1, s, word))
            return true;
          m1[i][j] = false;
        }
      }
    }
    return false;
  }

  bool dfs(vector<vector<char>>& board, int i, int j, int k, string s, string word) {
    if (i < 0 || j < 0 || i >= row || j >= col)
      return false;
    
    if (s.size() == word.size()) {
        return true;
    }

    if (!m1[i][j] && board[i][j] == word[k]) {
      m1[i][j] = true;
      s += word[k];
      if(dfs(board, i - 1, j, k + 1, s, word) || 
         dfs(board, i + 1, j, k + 1, s, word) ||
         dfs(board, i, j + 1, k + 1, s, word) || 
         dfs(board, i, j - 1, k + 1, s, word))
        return true;
      else {
        s.erase(s.end()-1);
        m1[i][j] = false;
      }
    }
    return false;
  }
};
```

## 剑指 Offer 38. 字符串的排列

回溯还需要系统的整理，自己对回溯的拿捏不是很好。比如这个题，想不到如何处理重复字符如 `aab`，于是用了集合，集合在转 vector，属实摆烂。

```cpp
class Solution {
public:
  vector<string> res;
  string tmp{""};
  set<string> s1;
  unordered_map<char, int> m1;
  vector<string> permutation(string s) {
    for (auto i : s) {
      m1[i] ++;
    }
    for (auto i : s) {
      tmp += i;
      m1[i]--;
      backtrack(s, tmp);
      tmp.erase(tmp.end()-1);
      m1[i]++;
    }
    res.resize(s1.size());
    copy(s1.begin(), s1.end(), res.begin());
    return res;
  }

  void backtrack(string& s, string& tmp) {
    if (tmp.size() == s.size()) {
      s1.insert(tmp);
      return;
    }
    for (int i = 0; i < s.size(); i++) {
      if (m1[s[i]] <= 0)
        continue;
      else {
        tmp += s[i];
        m1[s[i]]--;
        backtrack(s, tmp);
        tmp.erase(tmp.end() - 1);
        m1[s[i]]++;
      }
    }
  }
};
```

## 剑指 Offer 34. 二叉树中和为某一值的路径

这个题也算是二叉树中的经典问题了，求路径的和等于目标数值。关于递归：定义一个递归函数，然后无条件相信他。在递归函数中：

1. 进入递归函数，记录当前节点的数值
2. 如果是叶子节点，判断和是否满足目标值
3. 否则，继续向下遍历
4. 因为一条路径不满足需要回退掉之前叶子节点的值，所以在遍历结束后，需要删除之前添加节点的数值

```cpp
class Solution {
public:
  vector<vector<int>> res;
  int sumv{0};
  vector<int> tmp;
  vector<vector<int>> pathSum(TreeNode* root, int target) {
    sumv = target;
    dfs(root);
    return res;
  }

  int calc_sum(vector<int>& v) {
    int sum{0};
    for (auto i : v)
      sum += i;
    return sum;
  }

  void dfs(TreeNode* node) {
    if (node == nullptr)
      return;
    tmp.push_back(node->val);
    if (node->left == nullptr && node->right == nullptr) {
      if (calc_sum(tmp) == sumv) {
        res.push_back(tmp);
      }
    }
    dfs(node->left);
    dfs(node->right);
    tmp.pop_back();  
  }
};
```
