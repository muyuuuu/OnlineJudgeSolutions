// 题解：https://leetcode-cn.com/problems/minimum-remove-to-make-valid-parentheses/solution/yi-chu-wu-xiao-de-gua-hao-zhan-by-97wgl/

class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<int> stk;
        vector<bool> valid(s.size(), true);
        string res{""};
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                stk.push(i);
                valid[i] = false;
            }
            else if (s[i] == ')') {
                if (stk.empty()) {
                    valid[i] = false;
                } else {
                    valid[stk.top()] = true;
                    stk.pop();
                }
            }
        }
        for (int i = 0; i < s.size(); i++) {
            if (valid[i]) 
                res += s[i];
        }
        return res;
    }
};

// 执行用时：20 ms, 在所有 C++ 提交中击败了82.75%的用户
// 内存消耗：11.6 MB, 在所有 C++ 提交中击败了38.33%的用户