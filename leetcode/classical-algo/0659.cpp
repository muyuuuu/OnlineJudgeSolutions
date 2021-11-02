class Solution {
public:
    bool isPossible(vector<int>& nums) {
        unordered_map<int, int> freq, need;
        for (int i : nums){
            freq[i]++;
        }
        for (auto i : nums) {
            if (freq[i] <= 0)
                continue;
            if (need[i] > 0) {
                freq[i]--;
                need[i+1]++;
                need[i]--;
            } else if (freq[i] > 0 && freq[i + 1] > 0 && freq[i + 2] > 0) {
                freq[i]--;
                freq[i+1]--;
                freq[i+2]--;
                need[i+3]++;
            } else {
                return false;
            }
        }
        return true;
    }
};

// 执行用时： 100 ms , 在所有 C++ 提交中击败了 37.50% 的用户
// 内存消耗： 57 MB , 在所有 C++ 提交中击败了 59.09% 的用户
