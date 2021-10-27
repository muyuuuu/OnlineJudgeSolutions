class Solution {
public:
    vector<int> res;
    Solution(vector<int>& nums) {
        res = nums;
    }
    
    int pick(int target) {
        int a;
        int cnt{0};
        // 选择前 target 个
        for (int i = 0; i < res.size(); i++) {
            if (res[i] == target) {
                if (rand() % (++cnt) == 0) {
                    a = i;
                }
            }
        }
        return a;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * int param_1 = obj->pick(target);
 */

// 执行用时： 68 ms , 在所有 C++ 提交中击败了 43.06% 的用户
// 内存消耗： 34.6 MB , 在所有 C++ 提交中击败了 75.09% 的用户
