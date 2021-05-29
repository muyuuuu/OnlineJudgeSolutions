class Solution {
public:
    bool static cmp (const pair<int, int>& a, const pair<int, int>& b) {
        return a.second > b.second; // 按照频率从大到小排序
    }
    vector<int> rearrangeBarcodes(vector<int>& barcodes) {
        unordered_map<int, int> m;
        for(auto&i : barcodes) {
            m[i] ++;
        }
        vector<pair<int, int>> v(m.begin(), m.end());
        sort(v.begin(), v.end(), cmp);
        vector<int> res{barcodes};
        int idx{0};
        for (int i = 0; i < v.size(); i++) {
            while (v[i].second > 0) {
                res[idx] = v[i].first;
                idx += 2;
                v[i].second--;
                // 奇数位插满了插偶数位
                if (idx >= res.size()) 
                    idx = 1; 
            }
        }
        return res;
    }
};

// 执行用时：100 ms, 在所有 C++ 提交中击败了66.00%的用户
// 内存消耗：40.1 MB, 在所有 C++ 提交中击败了81.20%的用户