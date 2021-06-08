class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int l = 0, r = nums.size() - 1, m;
        while (l <= r) {
            m = l + (r - l) / 2;
            if (nums[m] == m) {
                l = m + 1;
            }
            else if (nums[m] > m) {
                r = m - 1;
            }  
        }
        return l;
    }
};

// 执行用时：16 ms, 在所有 C++ 提交中击败了84.59%的用户
// 内存消耗：16.8 MB, 在所有 C++ 提交中击败了5.91%的用户