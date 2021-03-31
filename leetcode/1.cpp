class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;
        map<int, int> arr;
        int n = nums.size();
        for (int i = 0; i < n; i++){
            arr[nums[i]] = i;
        }
        for (int i = 0; i < n; i++){
            int c = target - nums[i];
            if (arr[c] != 0 && i != arr[c]){
                ans.push_back(i);
                ans.push_back(arr[c]);
                break;
            }
        }
        return ans;
    }
};

// 执行用时：16 ms, 在所有 C++ 提交中击败了17.71%的用户
// 内存消耗：10.1 MB, 在所有 C++ 提交中击败了5.06%的用户