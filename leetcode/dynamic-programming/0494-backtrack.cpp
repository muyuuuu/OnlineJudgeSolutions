class Solution {
public:
  int t{0}, tmp{0}, res{0};
  int findTargetSumWays(vector<int> &nums, int target) {
    if (nums.size() == 0)
      return 0;
    t = target;
    dfs(nums, 0, tmp);
    return res;
  }

  void dfs(vector<int> &nums, int idx, int &tmp) {
    if (idx == nums.size()) {
      if (tmp == t) {
        res++;
      }
      return;
    }
    tmp += nums[idx];
    dfs(nums, idx + 1, tmp);
    tmp -= nums[idx];

    tmp -= nums[idx];
    dfs(nums, idx + 1, tmp);
    tmp += nums[idx];
  }
};
