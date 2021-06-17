class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        if (nums.size() == 0)
            return 0;
        int n = nums.size();
        int ans = INT_MAX;
        vector<int> s(n+1, 0);
        for (int i = 1; i <= n; i++) {
            s[i] = s[i-1] + nums[i-1];
        }
        for (int i = 1; i <= n; i++) {
            int t = target + s[i];
            auto b = lower_bound(s.begin(), s.end(), t);
            if (b != s.end())
                ans = min(ans, static_cast<int>(b - s.begin()) - i);
        }
        return ans == INT_MAX ? 0 : ans;
    }
};

// 执行用时：16 ms, 在所有 C++ 提交中击败了23.43%的用户
// 内存消耗：10.5 MB, 在所有 C++ 提交中击败了5.00%的用户