class Solution {
public:
    using PII = pair<int, int>;
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        priority_queue<PII, vector<PII>, greater<PII> > q;
        for (int i = 0; i < mat.size(); i++) {
            q.emplace(accumulate(mat[i].begin(), mat[i].end(), 0), i);
        }
        vector<int> res;
        for (int i = 0; i < k; i++) {
            res.push_back(q.top().second);
            q.pop();
        }
        return res;
    }
};

// 执行用时：12 ms, 在所有 C++ 提交中击败了88.95%的用户
// 内存消耗：10.2 MB, 在所有 C++ 提交中击败了53.37%的用户