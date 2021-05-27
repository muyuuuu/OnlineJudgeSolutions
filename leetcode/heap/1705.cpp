class Solution {
public:
    int eatenApples(vector<int>& apples, vector<int>& days) {
        priority_queue< pair<int, int>, vector< pair<int, int> >, greater< pair<int, int> > > q;
        int n = apples.size();
        int res{0};
        
        for (int i = 0; i < n || !q.empty(); i++) {
            // 先删除
            while (q.size() > 0 && q.top().first == i)
                q.pop();
            // 在添加
            if (i < n && apples[i] > 0) {
                q.emplace(make_pair(i + days[i], apples[i]));
            }
                
            // 开始吃
            if (!q.empty()) {
                auto a = q.top();
                res ++;
                a.second--;
                q.pop();
                if (a.second > 0)
                    q.push(a);
            }
        }
        return res;
    }
};

// 执行用时：232 ms, 在所有 C++ 提交中击败了25.00%的用户
// 内存消耗：46 MB, 在所有 C++ 提交中击败了62.90%的用户