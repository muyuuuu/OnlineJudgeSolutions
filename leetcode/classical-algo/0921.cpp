class Solution {
public:
  int minAddToMakeValid(string s) {
    int res{0};
    stack<char> stk;
    for (auto i : s) {
      if (i == ')') {
        if (stk.size() && stk.top() == '(') {
          stk.pop();
          res++;
          continue;
        } else {
          if (stk.empty()) {
            stk.push(i);
          } else if (stk.top() == ')') {
            stk.push(i);
          }
        }
      }

      if (i == '(') {
        stk.push(i);
      }
    }

    return s.size() - res * 2;
  }
};

// 执行用时： 0 ms , 在所有 C++ 提交中击败了 100.00% 的用户
// 内存消耗： 6.3 MB , 在所有 C++ 提交中击败了 8.24% 的用户
