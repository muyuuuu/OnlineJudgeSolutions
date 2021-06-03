class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;
        int mid;
        while (l <= r) {
            mid = l + (r - l) / 2;
            if (nums[mid] < target)
                l = mid + 1;
            else if (nums[mid] > target)
                r = mid - 1;
            else
                return mid;
        }
        return l;
    }
};

// 执行用时：4 ms, 在所有 C++ 提交中击败了88.57%的用户
// 内存消耗：9.2 MB, 在所有 C++ 提交中击败了94.35%的用户