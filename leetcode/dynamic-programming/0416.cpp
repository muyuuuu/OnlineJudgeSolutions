class Solution {
public:
  bool canPartition(vector<int> &nums) {
    int sumv = 0;
    for (auto i : nums)
      sumv += i;
    if (sumv % 2 != 0)
      return false;
    sumv /= 2;
    vector<vector<bool>> dp(nums.size(), vector<bool>(sumv + 1, false));
    for (int i = 0; i < nums.size(); i++)
      dp[i][0] = true;
    for (int i = 1; i < nums.size(); i++) {
      for (int j = 0; j <= sumv; j++) {
        if (j - nums[i - 1] < 0)
          dp[i][j] = dp[i - 1][j];
        else
          dp[i][j] = dp[i - 1][j] || dp[i - 1][j - nums[i - 1]];
      }
    }
    return dp[nums.size() - 1][sumv];
  }
};

// 执行用时： 240 ms , 在所有 C++ 提交中击败了 24.09% 的用户
// 内存消耗： 11.4 MB , 在所有 C++ 提交中击败了 49.07% 的用户
