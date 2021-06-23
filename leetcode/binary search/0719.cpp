class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int min = 0, max = nums.back() - nums.front();
        while (min < max) {
            int mid = (min + max) / 2;
            int count = 0;
            for (int l = 0, r = 0; r < nums.size(); r++) {
                while (l < r && nums[r] - nums[l] > mid) l++;
                count += r - l;
            }
            if (count >= k)
                max = mid;
            else
                min = mid + 1;
        }
        return min;
    }
};

// 执行用时：12 ms, 在所有 C++ 提交中击败了82.03%的用户
// 内存消耗：9.7 MB, 在所有 C++ 提交中击败了29.17%的用户