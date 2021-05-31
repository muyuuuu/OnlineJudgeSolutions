class Solution {
public:
    int kthSmallest(vector<vector<int>>& mat, int k) {
        int row = mat.size();
        vector<int> pre = mat[0];
        
        for (int i = 1; i < row; i++) {
            vector<int> cur;
            for (auto& x : pre) 
                for (auto& y : mat[i])
                    cur.push_back(x + y);
            sort(cur.begin(), cur.end());
            if (cur.size() > k)
                pre.assign(cur.begin(), cur.begin() + k);
            else
                pre = cur;
        }
        return pre[k-1];
    }
};

// 执行用时：148 ms, 在所有 C++ 提交中击败了52.71%的用户
// 内存消耗：32.9 MB, 在所有 C++ 提交中击败了55.04%的用户