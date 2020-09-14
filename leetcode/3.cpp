class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> m(128, 0);
        int ans = 0;
        int i = 0;
        for (int j = 0; j < s.size(); j++) {
            i = max(i, m[s[j]]);
            m[s[j]] = j + 1;
            ans = max(ans, j - i + 1);
        }
        return ans;
    }
};