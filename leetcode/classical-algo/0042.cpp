class Solution {
public:
  int trap(vector<int> &height) {
    int n = height.size();
    vector<int> l_max(n, 0);
    vector<int> r_max(n, 0);
    l_max[0] = height[0];
    r_max[n - 1] = height[n - 1];

    for (int i = 1; i < n; i++) {
      l_max[i] = max(height[i], l_max[i - 1]);
    }
    for (int i = n - 2; i >= 0; i--) {
      r_max[i] = max(height[i], r_max[i + 1]);
    }

    int res{0};
    for (int i = 1; i < n - 1; i++) {
      res += min(r_max[i], l_max[i]) - height[i];
    }
    return res;
  }
};

// 执行用时： 12 ms , 在所有 C++ 提交中击败了 39.93% 的用户
// 内存消耗： 15.6 MB , 在所有 C++ 提交中击败了 29.50% 的用户
