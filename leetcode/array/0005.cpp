class Solution {
public:
  string cal_substring(string &s, int l, int r) {
    while (l >= 0 && r < s.size()) {
      if (s[l] == s[r]) {
        l--;
        r++;
      } else {
        break;
      }
    }
    return s.substr(l + 1, r - l - 1);
  }

  string longestPalindrome(string s) {
    string res{""};
    for (int i = 0; i < s.size(); i++) {
      string l = cal_substring(s, i, i);
      string r = cal_substring(s, i, i + 1);
      res = res.size() > l.size() ? res : l;
      res = res.size() > r.size() ? res : r;
    }
    return res;
  }
};

// 执行用时： 20 ms , 在所有 C++ 提交中击败了 83.90% 的用户
// 内存消耗： 22.4 MB , 在所有 C++ 提交中击败了 59.37% 的用户
