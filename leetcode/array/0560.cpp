class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int res{0}, presum{0};
        unordered_map<int, int> m;
        m[0] = 1;
        for (int i = 0; i < nums.size(); i++) {
            presum += nums[i];
            if (m.count(presum - k))
                res += m[presum - k];
            m[presum]++;
        }
        return res;
    }
};

// 执行用时： 80 ms , 在所有 C++ 提交中击败了 35.36% 的用户
// 内存消耗： 35.2 MB , 在所有 C++ 提交中击败了 71.86% 的用户
