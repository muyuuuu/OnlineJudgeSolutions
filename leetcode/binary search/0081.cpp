class Solution {
public:

    bool subsearch(vector<int>& nums, int l, int r, int target) {
        while (l <= r) {
            int m = l + (r - l) / 2;
            if (nums[m] == target)
                return true;
            else if (nums[m] > target)
                r = m - 1;
            else
                l = m + 1;
        }
        return false;
    }

    bool search(vector<int>& a, int target) {
        set<int> s(a.begin(), a.end());
        vector<int> nums(s.begin(), s.end());
        int l = 0, r = nums.size() - 1;
        while (l <= r) {
            int m = l + (r - l) / 2;
            if (nums[m] > nums[r]) {
                l = m + 1;
            }
            else if (nums[m] < nums[r]) {
                r = m;
            }
            else {
                r--;
            }
        }
        if (l == 0) {
            r = nums.size() - 1;
            return subsearch(nums, l, r, target);
        }
        else if (nums[0] <= target && target <= nums[l-1])
            return subsearch(nums, 0, l - 1, target);
        return subsearch(nums, l, nums.size() - 1, target);
    }
};
