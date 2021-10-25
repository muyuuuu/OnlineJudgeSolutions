class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n = nums.size();
        vector<int> res;
        vector<int> tmp{nums.begin(), nums.end()};
        for (int i = 0; i < n; i++) {
            int x = nums[i];
            tmp[x - 1] += n;
        }
        for (int i = 0; i < n; i++) {
            if (tmp[i] <= n)
                res.push_back(i + 1);
        }
        return res;
    }
};

// 执行用时： 40 ms , 在所有 C++ 提交中击败了 90.21% 的用户
// 内存消耗： 34 MB , 在所有 C++ 提交中击败了 24.42% 的用户
