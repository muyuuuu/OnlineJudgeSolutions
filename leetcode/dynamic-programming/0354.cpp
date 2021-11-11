class Solution {
public:
  int maxEnvelopes(vector<vector<int>> &envelopes) {
    sort(envelopes.begin(), envelopes.end(),
         [&](vector<int> &v1, vector<int> &v2) {
           if (v1[0] != v2[0])
             return v1[0] < v2[0];
           return v1[1] > v2[1];
         });

    vector<int> dp(envelopes.size(), 1);
    for (int i = 0; i < envelopes.size(); i++) {
      for (int j = 0; j < i; j++) {
        if (envelopes[i][1] > envelopes[j][1]) {
          dp[i] = max(dp[i], dp[j] + 1);
        }
      }
    }
    int maxn = -10;
    for (auto i : dp) {
      if (i > maxn)
        maxn = i;
    }
    return maxn;
  }
};

// 执行用时： 880 ms , 在所有 C++ 提交中击败了 48.52% 的用户
// 内存消耗： 16 MB , 在所有 C++ 提交中击败了 29.79% 的用户
