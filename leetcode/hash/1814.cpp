class Solution {
public:
    int countNicePairs(vector<int>& nums) {
        vector<int> revNums;
        string valueStr;
        int value = 0;
        unordered_map<int, long long> myMap;
        for (auto& i : nums) {
            valueStr = to_string(i);
            reverse(valueStr.begin(), valueStr.end());
            myMap[i - stoi(valueStr)]++;
        }

        long long ans = 0;
        for (auto& it : myMap) {
            ans += (it.second - 1) * (it.second) / 2;
        }

        return (int)(ans % (1000000000 + 7));
    }
};

// 执行用时：244 ms, 在所有 C++ 提交中击败了10.32%的用户
// 内存消耗：55.8 MB, 在所有 C++ 提交中击败了8.79%的用户