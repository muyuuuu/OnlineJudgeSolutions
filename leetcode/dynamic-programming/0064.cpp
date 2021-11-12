class Solution {
public:
  int minPathSum(vector<vector<int>> &grid) {
    int n1 = grid.size();
    int n2 = grid[0].size();

    vector<vector<int>> dp(n1, vector<int>(n2, 0));

    dp[0][0] = grid[0][0];

    for (int i = 0; i < n1; i++) {
      for (int j = 0; j < n2; j++) {
        if (i == 0 && j == 0)
          continue;
        if (i == 0) {
          dp[i][j] = dp[i][j - 1] + grid[i][j];
        } else if (j == 0) {
          dp[i][j] = dp[i - 1][j] + grid[i][j];
        } else {
          dp[i][j] = grid[i][j] + min(dp[i - 1][j], dp[i][j - 1]);
        }
      }
    }

    return dp[n1 - 1][n2 - 1];
  }
};

// 执行用时： 8 ms , 在所有 C++ 提交中击败了 81.27% 的用户
// 内存消耗： 9.8 MB , 在所有 C++ 提交中击败了 54.51% 的用户
