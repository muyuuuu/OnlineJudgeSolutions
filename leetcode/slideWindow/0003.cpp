class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        if (s.size() == 0)
            return 0;

        int l{0}, r{0}, res{1};
        unordered_map<char, int> need;

        while (r < s.size()) {
            char c = s[r];
            r++;
            need[c]++;

            while (need[c] > 1) {
                char d = s[l];
                l++;
                if (need.count(d))
                    need[d]--;
            }

            res = max(res, r - l);
        }

        return res;
    }
};

// 执行用时： 20 ms , 在所有 C++ 提交中击败了 61.60% 的用户
// 内存消耗： 8.1 MB , 在所有 C++ 提交中击败了 67.79% 的用户
