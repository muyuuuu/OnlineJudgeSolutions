class Solution {
public:
  int minInsertions(string s) {
    int need{0}, res{0};
    for (auto i : s) {
      if (i == '(') {
        need += 2;
        if (need % 2 == 1) {
          res += 1;
          need -= 1;
        }
      }
      if (i == ')') {
        need--;
        if (need == -1) {
          res++;
          need = 1;
        }
      }
    }
    return res + need;
  }
};

// 执行用时： 28 ms , 在所有 C++ 提交中击败了 58.47% 的用户
// 内存消耗： 12.1 MB , 在所有 C++ 提交中击败了 41.95% 的用户
