class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> m;
        int ans{0};
        for (int st = 0, e = 0; e < s.size(); e++){
            if (m[s[e]] != 0){
                st = max(st, m[s[e]]);
            }
            m[s[e]] = e + 1;
            ans = max(ans, e - st + 1);
        }
        return ans;
    }
};

// 执行用时：4 ms, 在所有 C++ 提交中击败了97.03%的用户
// 内存消耗：8.2 MB, 在所有 C++ 提交中击败了46.39%的用户