- [深度优先遍历](#深度优先遍历)
  - [剑指 Offer 13. 机器人的运动范围](#剑指-offer-13-机器人的运动范围)

# 深度优先遍历

## 剑指 Offer 13. 机器人的运动范围

地上有一个m行n列的方格，从坐标 [0,0] 到坐标 [m-1,n-1] 。一个机器人从坐标 [0, 0] 的格子开始移动，它每次可以向左、右、上、下移动一格（不能移动到方格外），也不能进入行坐标和列坐标的数位之和大于k的格子。例如，当k为18时，机器人能够进入方格 [35, 37] ，因为3+5+3+7=18。但它不能进入方格 [35, 38]，因为3+5+3+8=19。请问该机器人能够到达多少个格子？

众所周知，`dfs` 算法搜索所有的结果，`bfs` 搜索最短路径，这道题显而易见使用 `dfs` 算法来搜索所有结果。在搜索过程中，加入各种限制即可，坐标号、行、列不能超过限制。此外还要避免重复搜索，记录已经搜索过的位置，如果下次再来到这个位置，直接跳过，避免多次搜索导致的结果错误。

```cpp
class Solution {
public:
  int maxn{0};
  unordered_map<int, unordered_map<int, bool>> map_;

  int count(int val) {
    int res{0};
    while (val != 0) {
      res += (val % 10);
      val /= 10;
    }
    return res;
  }

  int movingCount(int m, int n, int k) {
    dfs(0, 0, m, n, k);
    return maxn;
  }

  void dfs(int row, int col, int m, int n, int k) {
    if (count(row) + count(col) <= k && row < m && col < n) {
      if (map_[row][col] == false) {
        map_[row][col] = true;
        maxn++;
        dfs(row + 1, col, m, n, k);
        dfs(row, col + 1, m, n, k);
      }
    }
  }

};
```