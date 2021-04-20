class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<char, int> m;
        int ans{0};
        int n = s.size();
        for (int start = 0, end = 0; end < n; end++){
            if (m[s[end]] != 0){
                // 防止 abba，指针回退
                start = max(m[s[end]], start);
            }
            m[s[end]] = end + 1;
            ans = max(ans, end - start + 1);
        }
        return ans;
    }
};

// 执行用时：28 ms, 在所有 C++ 提交中击败了54.44%的用户
// 内存消耗：8.4 MB, 在所有 C++ 提交中击败了51.68%的用户