class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        int num {0}, maxn{-2}, col = wall.size(), res{0};
        for (auto& n : wall[0])
            num += n;
        // 空间爆炸
        vector<int> v(num - 1);

        for (int i = 0; i < col; i++){
            int c{0};
            for (int j = 0; j < wall[i].size() - 1; j++){
                if (j == 0){
                    c = wall[i][j] - 1;
                }
                else{
                    c += wall[i][j];
                }
                v[c] ++;
            }
        }
        for (auto& i : v){
            if (i > maxn){
                maxn = i;
            }
        }
        maxn == -2 ? res = col : res = col - maxn;
        return res;
    }
};