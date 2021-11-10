class Solution {
public:
  int minDistance(string word1, string word2) {
    int n1 = word1.size();
    int n2 = word2.size();
    vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1, 0));

    for (int i = 1; i <= n1; i++) {
      dp[i][0] = i;
    }

    for (int i = 1; i <= n2; i++) {
      dp[0][i] = i;
    }

    for (int i = 1; i <= n1; i++) {
      for (int j = 1; j <= n2; j++) {
        if (word1[i - 1] == word2[j - 1])
          dp[i][j] = dp[i - 1][j - 1];
        else {
          int a = dp[i - 1][j - 1] + 1;
          int b = dp[i][j - 1] + 1;
          int c = dp[i - 1][j] + 1;

          int d = min(a, b);
          dp[i][j] = min(d, c);
        }
      }
    }

    return dp[n1][n2];
  }
};

// 执行用时： 8 ms , 在所有 C++ 提交中击败了 90.77% 的用户
// 内存消耗： 8.8 MB , 在所有 C++ 提交中击败了 59.91% 的用户
