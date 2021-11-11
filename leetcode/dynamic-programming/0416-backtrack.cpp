class Solution {
public:
  int target, tmp{0};

  bool canPartition(vector<int> &nums) {
    int sumv = 0;
    for (auto i : nums)
      sumv += i;
    if (sumv % 2 != 0)
      return false;
    target = sumv / 2;
    return dfs(nums, 0, tmp);
  }

  bool dfs(vector<int> &nums, int idx, int &tmp) {
    if (tmp == target)
      return true;
    if (tmp > target)
      return false;
    if (idx >= nums.size()) {
      if (target == tmp)
        return true;
      return false;
    } else {
      tmp += nums[idx];
      if (dfs(nums, idx + 1, tmp))
        return true;
      tmp -= nums[idx];
      if (dfs(nums, idx + 1, tmp))
        return true;
    }
    return false;
  }
};

// TO
