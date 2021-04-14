// 行转成字符串，转的时候，如果行以0开头，则将行中所有数取反，如果是1开头，保持不变
// 然后看有多少个相同的字符串，选择其中个数最大的

class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        unordered_map<string, int> m;
        int res{0}, d{0};
        string s{""};
        for (auto& i : matrix){
            // 第一位是 0，那么 d 是 1，之后所有位取反
            // 第一位是 1，那么 d 是 0，之后所有位不变
            d = 1 ^ i[0];
            for (auto& j : i){
                s += j ^ d + '0';
            }
            m[s]++;
            res = max(res, m[s]);
            s.clear();
        }
        return res;
    }
};

// 执行用时：180 ms, 在所有 C++ 提交中击败了97.06%的用户
// 内存消耗：62.7 MB, 在所有 C++ 提交中击败了90.20%的用户