class Solution {
public:
  int maxSubArray(vector<int> &nums) {
    if (nums.size() == 1)
      return nums[0];
    vector<int> dp(nums.size(), 0);
    dp[0] = nums[0];
    for (int i = 1; i < nums.size(); i++) {
      dp[i] = max(nums[i], dp[i - 1] + nums[i]);
    }
    int n = -10006;
    for (auto i : dp) {
      if (i > n) {
        n = i;
      }
    }
    return n;
  }
};

// 执行用时： 88 ms , 在所有 C++ 提交中击败了 37.39% 的用户
// 内存消耗： 68.7 MB , 在所有 C++ 提交中击败了 7.44% 的用户
