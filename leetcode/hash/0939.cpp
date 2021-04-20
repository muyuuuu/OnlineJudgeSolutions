class Solution {
public:
    int minAreaRect(vector<vector<int>>& points) {
        unordered_map<int, set<int> > m;
        int res = INT_MAX;
        for (auto& p : points){
            m[p[0]].insert(p[1]);
        }
        for (int i = 0; i < points.size(); i++){
            auto x1 = points[i][0], y1 = points[i][1];
            for (int j = i + 1; j < points.size(); j++){
                auto x2 = points[j][0], y2 = points[j][1];
                if (x1 == x2 || y1 == y2)
                    continue;
                if (m[x1].count(y2) && m[x2].count(y1))
                    res = min(res, abs((x2-x1) * (y2-y1)));
            }
        }
        return res == INT_MAX ? 0 : res;
    }
};

// 执行用时：660 ms, 在所有 C++ 提交中击败了36.08%的用户
// 内存消耗：17.8 MB, 在所有 C++ 提交中击败了69.07%的用户