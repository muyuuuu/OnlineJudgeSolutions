class Solution {
public:
  int maxCoins(vector<int> &nums) {
    vector<int> vals;
    vals.push_back(1);
    for (auto i : nums)
      vals.push_back(i);
    vals.push_back(1);
    int n = nums.size();

    vector<vector<int>> dp(n + 2, vector<int>(n + 2, 0));

    for (int i = 0; i <= n + 1; i++) {
      for (int j = i - 2; j >= 0; j--) {
        for (int k = i - 1; k > j; k--) {
          auto sum = vals[j] * vals[k] * vals[i];
          sum += (dp[j][k] + dp[k][i]);
          dp[j][i] = max(dp[j][i], sum);
        }
      }
    }

    return dp[0][n + 1];
  }
};

// 执行用时： 592 ms , 在所有 C++ 提交中击败了 60.42% 的用户
// 内存消耗： 10 MB , 在所有 C++ 提交中击败了 29.99% 的用户
