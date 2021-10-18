class Solution {
public:
    string tmp;
    vector<string> res;
    vector<string> generateParenthesis(int n) {
        dfs(n, n);
        return res;
    }

    void dfs(int r, int l) {
        if (r < 0 || l < 0)
            return;
        if (r < l)
            return;
        if (r == 0 && l == 0) {
            res.push_back(tmp);/*  */
            return;
        }
        tmp.push_back('(');
        dfs(r, l - 1);
        tmp.pop_back();

        tmp.push_back(')');
        dfs(r - 1, l);
        tmp.pop_back();
    }
};

// 执行用时： 4 ms , 在所有 C++ 提交中击败了 72.71% 的用户
// 内存消耗： 11.2 MB , 在所有 C++ 提交中击败了 72.39% 的用户
