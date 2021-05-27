class Solution {
public:
    int eatenApples(vector<int>& apples, vector<int>& days) {
        // 腐烂日期到数量
        map<int, int> day2cnt;
        // 记录数量
        int res = 0;
        int n = apples.size();
        for (int i = 0; i < n || !day2cnt.empty(); ++i) {
            // 先删除已经过期的苹果
            day2cnt.erase(i);
            // 更新过期日期的苹果数量
            if (i < n && apples[i] > 0) {
                day2cnt[i+days[i]] += apples[i];
            }

            // 至少有苹果的情况
            if (!day2cnt.empty()) {
                // 先吃最早要腐烂的苹果，就是过期时间最早的
                auto iter = day2cnt.begin();
                iter->second--;
                // 计数器更新
                res ++;
                // 如果没有了，则从map表里删除掉
                if (iter->second == 0) {
                    day2cnt.erase(iter);
                }
            }
        }
        return res;
    }
};

// 执行用时：168 ms, 在所有 C++ 提交中击败了70.56%的用户
// 内存消耗：53.3 MB, 在所有 C++ 提交中击败了18.15%的用户