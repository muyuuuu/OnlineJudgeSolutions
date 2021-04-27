class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> stk;
        int tmp{0};
        for (auto& i : num) {
            if (i == '0' && stk.empty())
                continue;
            else {
                // 栈非空小于栈顶，压栈
                while (!stk.empty() && i < stk.top()) {
                    tmp ++;
                    // 达到删除次数，不再弹栈
                    if (tmp <= k) {
                        stk.pop();
                    }
                    else
                        break;
                }
                // 0不能是栈首
                if (i != '0' || !stk.empty())
                    stk.push(i);
            }
        }

        string res{""};
        // 没删够，继续删
        if (tmp <= k) {
            while (tmp < k && !stk.empty()) {
                tmp ++;
                stk.pop();
            }
        }
        if (stk.empty())
            return "0";
        while (!stk.empty()) {
            res += stk.top();
            stk.pop();
        }
        reverse(res.begin(), res.end());
        return res;

    }
};

// 执行用时：4 ms, 在所有 C++ 提交中击败了73.80%的用户
// 内存消耗：6.9 MB, 在所有 C++ 提交中击败了55.42%的用户