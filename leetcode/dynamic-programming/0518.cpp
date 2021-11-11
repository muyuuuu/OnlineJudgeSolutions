class Solution {
public:
  int change(int amount, vector<int> &coins) {
    int n = coins.size();
    // n 个物品，装满 amount 的方法
    vector<vector<int>> dp(n + 1, vector<int>(amount + 1, 0));
    for (int i = 0; i <= n; i++)
      dp[i][0] = 1;

    for (int i = 1; i <= n; i++) {
      // dp[i-1] 会限制 coins 也是 i-1，导致 coins 最后一个无法遍历到，所以 dp
      // 是 n+1 大小的
      for (int j = 1; j <= amount; j++) {
        if (j - coins[i - 1] < 0)
          dp[i][j] = dp[i - 1][j];
        else
          dp[i][j] = dp[i - 1][j] + dp[i][j - coins[i - 1]];
      }
    }
    return dp[n][amount];
  }
};

// 执行用时： 48 ms , 在所有 C++ 提交中击败了 8.93% 的用户
// 内存消耗： 18.1 MB , 在所有 C++ 提交中击败了 9.70% 的用户
