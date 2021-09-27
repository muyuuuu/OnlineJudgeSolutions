class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int slow{0}, fast{0};
        while (fast < nums.size()) {
            if (nums[fast] != 0) {
                nums[slow] = nums[fast];
                slow++;
            }
            fast++;
        }

        while (slow < nums.size()) {
            nums[slow] = 0;
            slow++;
        }
    }
};

// 执行用时： 12 ms , 在所有 C++ 提交中击败了 17.37% 的用户
// 内存消耗： 18.7 MB , 在所有 C++ 提交中击败了 5.01% 的用户
