class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> dp(nums.size(), 1);
        for (int i = 0; i < nums.size(); i++) {
            for (int j = 0; j < i; j++) {
                if (nums[i] > nums[j])
                    dp[i] = max(dp[i], dp[j] + 1);
            }
        }

        int val{-2};
        for (int i = 0; i < dp.size(); i++)
            val = max(val, dp[i]);

        return val;
    }
};

// 执行用时： 276 ms , 在所有 C++ 提交中击败了 27.11% 的用户
// 内存消耗： 10.2 MB , 在所有 C++ 提交中击败了 71.55% 的用户
