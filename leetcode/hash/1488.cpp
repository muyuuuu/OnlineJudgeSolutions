class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        vector<int> ans(rains.size(), 1);
        unordered_map<int, int> water;
        set<int> zero;

        for (int i = 0; i < rains.size(); i++) {
            int r = rains[i];
            // 将晴天的日期全部记录到 set<int> zero 中
            // 遇到晴天时先不用管抽哪个湖
            if (r == 0) {
                zero.insert(i);
                continue;
            }
            // 当下雨时，湖泊已经水满了时，我们可以查询到上次下雨的日期
            if (water.count(r) != 0) {
                // 通过这个日期在晴天记录中查找对应的晴天日期
                auto it = zero.lower_bound(water[r]);
                // 如果找到了，就可以使用那一天抽水，找不到就不可避免的洪水了
                if (it == zero.end())
                    return {};
                ans[*it] = r;
                zero.erase(it);
            }
            // 使用 unordered_map<int, int> water 来记录每个湖泊上一次下雨的日期
            water[r] = i;
            ans[i] = -1;
        }

        return ans;
    }    
};

// 执行用时：332 ms, 在所有 C++ 提交中击败了80.38%的用户
// 内存消耗：107.2 MB, 在所有 C++ 提交中击败了74.36%的用户