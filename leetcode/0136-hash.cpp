class Solution {
public:
    int singleNumber(vector<int>& nums) {
        map <int, int> m;
        int len = nums.size(), result{0};
        for (int i = 0; i < len; i++){
            m[nums[i]]++;
        }
        for (int i = 0; i < len; i++){
            if (m[nums[i]] == 1){
                result = nums[i];
                break;
            }
        }
        return result;
    }
};

// 执行用时：60 ms, 在所有 C++ 提交中击败了8.03%的用户
// 内存消耗：20.3 MB, 在所有 C++ 提交中击败了5.08%的用户