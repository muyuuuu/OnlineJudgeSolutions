class Solution {
public:
    int search(vector<int>& nums, int target) {
        auto left = lower_bound(nums.begin(), nums.end(), target);
        auto right = upper_bound(nums.begin(), nums.end(), target);
        return right - left;
    }
};

// 执行用时：8 ms, 在所有 C++ 提交中击败了80.59%的用户
// 内存消耗：12.9 MB, 在所有 C++ 提交中击败了45.85%的用户

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;
        int mid;
        while (l <= r) {
            mid = l + (r - l) / 2;
            if (nums[l] == target) {
                if (nums[r] == target)
                    return r - l + 1;
                else if (nums[mid] == target)
                    r--;
                else
                    r = mid - 1;
            }
            else if (nums[mid] == target)
                l++;
            else if (nums[mid] < target)
                l = mid + 1;
            else 
                r = mid - 1;
        }
        return r - l + 1;
    }
};

// 执行用时：8 ms, 在所有 C++ 提交中击败了80.59%的用户
// 内存消耗：12.8 MB, 在所有 C++ 提交中击败了66.68%的用户