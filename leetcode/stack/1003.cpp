class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;
        int cnt{0};
        for (auto& i : s) {
            if (i == 'c') {
                if (!stk.empty()) {
                    cnt = 0;
                    if (stk.top() == 'b') {
                        stk.pop();
                        cnt++;
                    }
                    if (!stk.empty() && stk.top() == 'a') {
                        cnt ++;
                        stk.pop();
                    }
                }
                if (cnt != 2) {
                    stk.push(i);
                }
            }
            else
                stk.push(i);
        }
        bool flag{false};
        if (stk.empty())
            flag = true;
        return flag;
    }
};

// 执行用时：16 ms, 在所有 C++ 提交中击败了45.74%的用户
// 内存消耗：8.4 MB, 在所有 C++ 提交中击败了27.86%的用户