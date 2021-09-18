class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;

        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (nums[mid] == target)
                return mid;
            else if (nums[mid] < target)
                l = mid + 1;
            else if (nums[mid] > target)
                r = mid - 1;
        }

        return -1;
    }
};

// 执行用时： 28 ms , 在所有 C++ 提交中击败了 87.23% 的用户
// 内存消耗： 26.8 MB , 在所有 C++ 提交中击败了 85.73% 的用户
