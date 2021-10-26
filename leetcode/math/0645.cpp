class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int dou, miss, idx, n = nums.size();
        for (int i = 0; i < n; i++) {
            int idx = abs(nums[i]) - 1;
            if (nums[idx] < 0)
                dou = abs(nums[i]);
            else
                nums[idx] *= -1;
        }

        for (int i = 0; i < n; i++) {
            if (nums[i] > 0) {
                miss = i + 1;
            }
        }

        return {dou, miss};
    }
};

// 执行用时： 16 ms , 在所有 C++ 提交中击败了 99.03% 的用户
// 内存消耗： 20.9 MB , 在所有 C++ 提交中击败了 82.98% 的用户
