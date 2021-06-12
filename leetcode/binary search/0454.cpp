class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        unordered_map<int, int> m;
        int res{0};
        for (auto& i : nums1)
            for (auto&& j : nums2)
                m[i+j]++;
        for (auto& i : nums3)
            for (auto& j : nums4)
                res += m[-i-j];
        return res;
    }
};

// 执行用时：240 ms, 在所有 C++ 提交中击败了73.46%的用户
// 内存消耗：23.9 MB, 在所有 C++ 提交中击败了52.44%的用户