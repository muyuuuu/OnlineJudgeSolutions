class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int l = 0;
        int r = numbers.size() - 1;
        vector<int> res; 

        while (l <= r) {
            int s = numbers[l] + numbers[r];
            if (s == target){
                return {l+1, r+1};
            }

            else if (s > target) {
                r -= 1;
            }

            else if (s < target) {
                l += 1;
            }
        }

        return res;
    }
};

// 执行用时： 4 ms , 在所有 C++ 提交中击败了 86.80% 的用户
// 内存消耗： 9.5 MB , 在所有 C++ 提交中击败了 16.21% 的用户
