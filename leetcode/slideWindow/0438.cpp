class Solution {
public:
    vector<int> findAnagrams(string s, string p) {

        int l{0}, r{0}, valid{0};
        unordered_map<char, int> need, win;
        vector<int> res;

        for (const auto& i : p)
            need[i]++;

        while (r < s.size()) {

            char c = s[r];
            r++;

            if (need.count(c)) {
                win[c]++;
                if (need[c] == win[c])
                    valid++;
            }

            while (r - l >= p.size()) {
                if (valid == need.size())
                    res.push_back(l);

                char d = s[l];
                l++;

                if (need.count(d)) {
                    if (need[d] == win[d])
                        valid--;
                    win[d]--;
                }
            }
        }

        return res;
    }
};

// 执行用时： 24 ms , 在所有 C++ 提交中击败了 28.91% 的用户
// 内存消耗： 8.5 MB , 在所有 C++ 提交中击败了 53.08% 的用户
