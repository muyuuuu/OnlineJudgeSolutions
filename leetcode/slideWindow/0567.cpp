class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int l{0}, r{0}, valid{0};
        unordered_map<char, int> need, win;

        for (const auto& i : s1)
            need[i]++;

        cout << need.size() << " " << s1.size() << endl;

        while (r < s2.size()) {

            char c = s2[r];
            r++;

            if (need.count(c)) {
                win[c] ++;
                if (win[c] == need[c])
                    valid++;
            }

            while (r - l >= s1.size()) {
                if (valid == need.size())
                    return true;

                char d = s2[l];
                l++;

                if (need.count(d)) {
                    if (win[d] == need[d])
                        valid--;
                    win[d]--;
                }

            }
        }

        return false;
    }
};

// 执行用时： 28 ms , 在所有 C++ 提交中击败了 14.06% 的用户
// 内存消耗： 7.2 MB , 在所有 C++ 提交中击败了 35.27% 的用户
