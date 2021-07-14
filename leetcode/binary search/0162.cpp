class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int l = 0, r = nums.size() - 1, m, n = nums.size();
        while (l <= r) {
            m = l + (r - l) / 2;
            if (m + 1 < n && nums[m] > nums[m + 1])
                r = m - 1;
            else 
                l = m + 1;
        }
        return l < n ? l : l - 1;
    }
};

// 执行用时：4 ms, 在所有 C++ 提交中击败了87.54%的用户
// 内存消耗：8.6 MB, 在所有 C++ 提交中击败了46.11%的用户