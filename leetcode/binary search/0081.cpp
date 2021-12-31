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
        return subsearch(nums, 0, nums.size() - 1, target);
    }
};
