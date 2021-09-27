class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() == 0) {
            return 0;
        }
        int slow{0}, fast{0};
        while (fast < nums.size()) {
            if (nums[slow] != nums[fast]) {
                slow++;
                nums[slow] = nums[fast];
            }
            fast++;
        }
        return slow + 1;
    }
};

// 执行用时： 8 ms , 在所有 C++ 提交中击败了 86.72% 的用户
// 内存消耗： 17.9 MB , 在所有 C++ 提交中击败了 73.25% 的用户
