class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        unordered_map<int, int> mp;
        long long int maxnum {0}, temp{0};
        for(auto wl : wall) {
            for(int i = 0; i < wl.size() - 1; ++i) {
                temp += wl[i];
                mp[temp]++;
                maxnum = maxnum > mp[temp] ? maxnum : mp[temp];
            }
            temp = 0;
        }
        return wall.size() - maxnum;
    }
};

// 执行用时：52 ms, 在所有 C++ 提交中击败了83.83%的用户
// 内存消耗：22.8 MB, 在所有 C++ 提交中击败了10.67%的用户