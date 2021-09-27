class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int slow{0}, fast{0};
        while (fast < nums.size()) {
            if (nums[fast] != val) {
                nums[slow] = nums[fast];
                slow++;
            }
            fast++;
        }
        return slow;
    }
};

// 执行用时： 4 ms , 在所有 C++ 提交中击败了 54.86% 的用户
// 内存消耗： 8.6 MB , 在所有 C++ 提交中击败了 29.99% 的用户
