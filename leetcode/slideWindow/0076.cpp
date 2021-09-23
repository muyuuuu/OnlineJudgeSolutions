class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> need, win;
        int l{0}, r{0}, len{INT_MAX}, valid{0}, start{0};
        
        for(const auto& i : t)
            need[i] ++;

        while (r < s.size()) {

            char c = s[r];
            r++;

            if (need.count(c)) {
                win[c]++;
                if (win[c] == need[c])
                    valid++;
            }

            while (valid == need.size()) {
                if (r - l < len) {
                    len = r - l;
                    start = l;
                }

                char d = s[l];
                l++;

                if (need.count(d)) {
                    if (win[d] == need[d])
                        valid--;
                    win[d]--;
                }
            }

        }

        return len == INT_MAX ? "" : s.substr(start, len);

    }
};

// 执行用时： 20 ms , 在所有 C++ 提交中击败了 65.63% 的用户
// 内存消耗： 7.6 MB , 在所有 C++ 提交中击败了 56.96% 的用户
