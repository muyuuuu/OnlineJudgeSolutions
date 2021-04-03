class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int result{0};
        int len = nums.size();
        for (int i = 0; i < len; i++){
            result = result ^ nums[i];
        }
        return result;
    }
};

// 执行用时：16 ms, 在所有 C++ 提交中击败了91.18%的用户
// 内存消耗：16.4 MB, 在所有 C++ 提交中击败了85.55%的用户