class Solution {
private:
    vector<int> tmp;
    vector<vector<int>> res;
public:
    vector<vector<int>> combine(int n, int k) {
        dfs(1, n, k);
        return res;
    }

    void dfs(int cur, int n, int k) {
        if (tmp.size() + n - cur + 1 < k)
            return;
        if (tmp.size() == k) {
            res.push_back(tmp);
            return;
        }
        else {
            tmp.push_back(cur);
            dfs(cur + 1, n, k);
            tmp.pop_back();
            dfs(cur + 1, n, k);
        }
    }
};

// 执行用时： 4 ms , 在所有 C++ 提交中击败了 99.14% 的用户
// 内存消耗： 18.6 MB , 在所有 C++ 提交中击败了 9.71% 的用户
