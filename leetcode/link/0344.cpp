class Solution {
public:
    void reverseString(vector<char>& s) {
        int l = 0;
        int r = s.size() - 1;
        while (l < r) {
            char t = s[l];
            s[l] = s[r];
            s[r] = t;
            l++;
            r--;
        }
    }
};

// 执行用时： 16 ms , 在所有 C++ 提交中击败了 87.47% 的用户
// 内存消耗： 22.4 MB , 在所有 C++ 提交中击败了 97.87% 的用户
