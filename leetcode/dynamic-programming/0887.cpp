class Solution {
public:
  int superEggDrop(int k, int n) {
    // n + 1 次，k 个鸡蛋，测到的层数
    vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= k; j++) {
        int a = dp[i - 1][j];         // 鸡蛋没碎
        int b = dp[i - 1][j - 1] + 1; // 鸡蛋碎了
        dp[i][j] = a + b;
        if (dp[i][j] >= n)
          return i;
      }
    }
    return n;
  }
};

// 执行用时： 4 ms , 在所有 C++ 提交中击败了 85.51% 的用户
// 内存消耗： 28.9 MB , 在所有 C++ 提交中击败了 32.26% 的用户
