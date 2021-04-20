class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        int res{0};
        unordered_map<int, int> m;
        for (auto& i : nums){
            if (m[i] != 0){
                res ++;
                m[i] --;
            }
            else {
                m[k - i] ++; 
            }
        }
        return res;
    }
};

// 执行用时：192 ms, 在所有 C++ 提交中击败了41.52%的用户
// 内存消耗：71.1 MB, 在所有 C++ 提交中击败了16.96%的用户