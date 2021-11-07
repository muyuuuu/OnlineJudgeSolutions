class Solution {
public:
  int coinChange(vector<int> &coins, int amount) {
    int s{0};
    vector<int> dp(amount + 1, amount + 10);
    dp[0] = 0;
    for (int i = 0; i < dp.size(); i++) {
      for (auto j : coins) {
        if (i < j)
          continue;
        dp[i] = min(dp[i], dp[i - j] + 1);
      }
    }
    if (dp[amount] == amount + 10)
      return -1;
    return dp[amount];
  }
};

// 执行用时： 68 ms , 在所有 C++ 提交中击败了 74.23% 的用户
// 内存消耗： 14.1 MB , 在所有 C++ 提交中击败了 50.24% 的用户
