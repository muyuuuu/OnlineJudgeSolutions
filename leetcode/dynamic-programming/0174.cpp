class Solution {
public:
  int calculateMinimumHP(vector<vector<int>> &dungeon) {
    int n1 = dungeon.size(), n2 = dungeon[0].size();
    vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1, INT_MAX));
    dp[n1][n2 - 1] = 1;
    dp[n1 - 1][n2] = 1;

    for (int i = n1 - 1; i >= 0; i--) {
      for (int j = n2 - 1; j >= 0; j--) {
        int a = min(dp[i + 1][j], dp[i][j + 1]);
        dp[i][j] = max(a - dungeon[i][j], 1);
      }
    }

    return dp[0][0];
  }
};

// 执行用时： 0 ms , 在所有 C++ 提交中击败了 100.00% 的用户
// 内存消耗： 8.8 MB , 在所有 C++ 提交中击败了 31.06% 的用户
