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
