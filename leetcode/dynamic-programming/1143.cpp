class Solution {
public:
  int longestCommonSubsequence(string text1, string text2) {
    vector<vector<int>> dp(text1.size(), vector<int>(text2.size(), 0));
    for (int i = 0; i < text2.size(); i++) {
      if (text2[i] == text1[0]) {
        for (int j = i; j < text2.size(); j++) {
          dp[0][j] = 1;
        }
        break;
      }
    }
    for (int i = 0; i < text1.size(); i++) {
      if (text1[i] == text2[0]) {
        for (int j = i; j < text1.size(); j++) {
          dp[j][0] = 1;
        }
        break;
      }
    }
    for (int i = 1; i < text1.size(); i++) {
      for (int j = 1; j < text2.size(); j++) {
        int a =
            text1[i] == text2[j] ? (dp[i - 1][j - 1] + 1) : dp[i - 1][j - 1];
        int b = dp[i][j - 1];
        int c = dp[i - 1][j];
        dp[i][j] = max(a, max(b, c));
      }
    }
    return dp[text1.size() - 1][text2.size() - 1];
  }
};

// 执行用时： 28 ms , 在所有 C++ 提交中击败了 23.63% 的用户
// 内存消耗： 12.7 MB , 在所有 C++ 提交中击败了 64.65% 的用户
