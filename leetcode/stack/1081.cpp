class Solution {
public:
    string smallestSubsequence(string s) {
        stack<char> stk;
        array<bool, 26> isin{false};
        array<int, 26> cnt{0};

        for (auto&i : s) {
            cnt[i - 'a'] ++;
        }

        for (auto& i : s) {
            cnt[i - 'a'] --;
            // 不在里面
            if (!isin[i - 'a']) {
                if (!stk.empty()) {
                    while (!stk.empty() && i < stk.top()) {
                        if (cnt[stk.top() - 'a'] > 0) {
                            isin[stk.top() - 'a'] = false;
                            stk.pop();
                        }
                        else
                            break;
                    }
                }
                stk.push(i);
                isin[i - 'a'] = true;
            }
        }

        string res{""};
        while (!stk.empty()) {
            res += stk.top();
            stk.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};

// 执行用时：0 ms, 在所有 C++ 提交中击败了100.00%的用户
// 内存消耗：6 MB, 在所有 C++ 提交中击败了96.72%的用户