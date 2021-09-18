class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> res;
        
        if (nums.size() == 0)
            return {-1, -1};

        int l = 0, r = nums.size();
        // 左边界，右侧是否溢出
        while (l < r) {
            int mid = l + (r - l) / 2;
            if (nums[mid] == target) {
                r = mid;
            }
            else if (nums[mid] > target) {
                r = mid;
            }
            else if (nums[mid] < target) {
                l = mid + 1;
            }
        }
        
        if (l >= nums.size() || nums[l] != target)
            res.push_back(-1);
        else
            res.push_back(l);

        // 右边界
        l = 0, r = nums.size();
        while (l < r) {
            int mid = l + (r - l) / 2;
            // l 不等于 mid，所以要 -1 
            if (nums[mid] == target) {
                l = mid + 1;
            }
            else if (nums[mid] > target) {
                r = mid;
            }
            else if (nums[mid] < target) {
                l = mid + 1;
            }
        }
        
        // 查右边界，左侧是否溢出
        if (l - 1 < 0 || nums[l-1] != target)
            res.push_back(-1);
        else
            res.push_back(l-1);

        return res;
    }
};

// 执行用时： 16 ms , 在所有 C++ 提交中击败了 25.93% 的用户
// 内存消耗： 13.2 MB , 在所有 C++ 提交中击败了 77.03% 的用户
