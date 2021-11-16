class Solution {
public:
  int longestPalindromeSubseq(string s) {
    int n = s.size();
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
    for (int i = 0; i < n; i++)
      dp[i][i] = 1;
    for (int i = 0; i <= n; i++) {
      for (int j = i - 1; j >= 0; j--) {
        if (s[i] == s[j]) {
          dp[i][j] = dp[i - 1][j + 1] + 2;
        } else
          dp[i][j] = max(dp[i - 1][j], dp[i][j + 1]);
      }
    }
    return dp[n][0];
  }
};

// 执行用时： 112 ms , 在所有 C++ 提交中击败了 30.48% 的用户
// 内存消耗： 71.4 MB , 在所有 C++ 提交中击败了 6.87% 的用户
