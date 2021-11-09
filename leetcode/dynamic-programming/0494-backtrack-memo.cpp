class Solution {
public:
  unordered_map<string, int> ha;

  int findTargetSumWays(vector<int> &nums, int target) {
    if (nums.size() == 0)
      return 0;
    return dp(nums, 0, target);
  }

  int dp(vector<int> &nums, int idx, int tmp) {
    if (idx == nums.size()) {
      if (tmp == 0)
        return 1;
      return 0;
    }

    string s{""};
    s = to_string(idx) + '-' + to_string(tmp);
    if (ha.count(s)) {
      return ha[s];
    }

    int res =
        dp(nums, idx + 1, tmp + nums[idx]) + dp(nums, idx + 1, tmp - nums[idx]);
    ha[s] = res;
    return res;
  }
};

// 执行用时： 636 ms , 在所有 C++ 提交中击败了 32.40% 的用户
// 内存消耗： 87.8 MB , 在所有 C++ 提交中击败了 5.02% 的用户
