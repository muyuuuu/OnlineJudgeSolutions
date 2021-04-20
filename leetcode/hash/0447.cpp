class Solution {
public:
    int numberOfBoomerangs(vector<vector<int>>& points) {
        int res{0}, dx, dy;
        for (auto &p : points){
            unordered_map<int, int> m;
            for (auto &q : points){
                dx = p[0] - q[0];
                dy = p[1] - q[1];
                m[dx*dx + dy*dy]++;
            }
            for (auto &q : m){
                res += q.second * (q.second - 1);
            }
        }
        return res;
    }
};

// 执行用时：652 ms, 在所有 C++ 提交中击败了62.79%的用户
// 内存消耗：121.2 MB, 在所有 C++ 提交中击败了74.62%的用户