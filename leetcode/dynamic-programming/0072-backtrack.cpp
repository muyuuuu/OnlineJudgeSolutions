class Solution {
public:
  string w1, w2;
  unordered_map<string, int> m;

  int minDistance(string word1, string word2) {
    w1 = word1;
    w2 = word2;
    return dp(0, 0);
  }

  int dp(int i, int j) {

    string s = to_string(i) + "-" + to_string(j);
    if (m.count(s))
      return m[s];

    if (i >= w1.size())
      return w2.size() - j;
    if (j >= w2.size())
      return w1.size() - i;

    if (w1[i] == w2[j]) {
      m[s] = dp(i + 1, j + 1);
      return m[s];
    } else {
      int a1 = dp(i + 1, j + 1) + 1; // replace
      int a2 = dp(i, j + 1) + 1;     // insert
      int a3 = dp(i + 1, j) + 1;     // delete

      auto b = min(a1, a2);
      m[s] = min(b, a3);
      return min(b, a3);
    }
  }
};

// 执行用时： 132 ms , 在所有 C++ 提交中击败了 5.62% 的用户
// 内存消耗： 23.8 MB , 在所有 C++ 提交中击败了 5.69% 的用户
