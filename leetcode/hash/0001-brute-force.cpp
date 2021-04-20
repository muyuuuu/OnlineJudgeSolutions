class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;
        int len = nums.size();
        int f{0};
        for (int i = 0; i < len; i++){
            for (int j = i + 1; j < len; j++){
                if (nums[i] + nums[j] == target){
                    ans.push_back(i);
                    ans.push_back(j);
                    f = 1;
                    break;
                }
            }
            if (f == 1)
                break;
        }
        return ans;
    }
};

// 执行用时：0 ms, 在所有 C++ 提交中击败了100.00%的用户
// 内存消耗：8.7 MB, 在所有 C++ 提交中击败了51.59%的用户