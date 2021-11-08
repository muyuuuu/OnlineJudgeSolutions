class Solution {
public:
  int minFallingPathSum(vector<vector<int>> &matrix) {
    int row = matrix.size();
    int col = matrix[0].size();
    if (row == 0 || col == 0)
      return 0;
    vector<vector<int>> dp(row, vector<int>(col, INT_MAX));
    for (int i = 0; i < row; i++) {
      for (int j = 0; j < col; j++) {
        if (i == 0) {
          dp[i][j] = matrix[i][j];
        } else if (j == 0) {
          dp[i][j] = min(dp[i - 1][j], dp[i - 1][j + 1]) + matrix[i][j];
        } else if (j == col - 1) {
          dp[i][j] = min(dp[i - 1][j], dp[i - 1][j - 1]) + matrix[i][j];
        } else {
          auto a = min(dp[i - 1][j], dp[i - 1][j - 1]);
          auto b = min(a, dp[i - 1][j + 1]);
          dp[i][j] = b + matrix[i][j];
        }
      }
    }

    int minn = INT_MAX;
    for (int i = 0; i < col; i++) {
      if (dp[row - 1][i] < minn) {
        minn = dp[row - 1][i];
      }
    }
    return minn;
  }
};

// 执行用时： 16 ms , 在所有 C++ 提交中击败了 12.49% 的用户
// 内存消耗： 10 MB , 在所有 C++ 提交中击败了 5.06% 的用户
