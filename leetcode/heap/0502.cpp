// class Solution {
// private:
//     struct node {
//         int cap;
//         int pro;
//         bool flag{false};
//     };
// public:
//     static bool cmp (node a, node b) {
//         if (a.cap < b.cap)
//             return true;
//         else if (a.cap == b.cap)
//             return a.pro > b.pro;
//         return false;
//     }
//     int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
//         vector<node> v;
//         node tmp;
//         for (int i = 0; i < profits.size(); i++) {
//             tmp.pro = profits[i];
//             tmp.cap = capital[i];
//             v.push_back(tmp);
//         }
//         sort(v.begin(), v.end(), cmp);
//         int len = profits.size();
//         for (int i = 0; i < k && i < len; i++) {
//             int maxn = 0, idx = i, key{0};
//             // 获取当前成本下的最大利益
//             while (w >= v[idx].cap && idx < len) {
//                 if (v[idx].pro > maxn && v[idx].flag == false) {
//                     maxn = v[idx].pro;
//                     key = idx;
//                 }
//                 idx++;
//             }
//             w += maxn;
//             v[key].flag = true;
//         }
//         return w;
//     }
// };

class Solution {
public:
    using PII = pair<int, int>;
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int n = profits.size();
        priority_queue<int> m;
        priority_queue<PII, vector<PII>, greater<PII>> q;
        for (int i = 0; i < n; i++) {
            q.emplace(capital[i], profits[i]);
        }
        n = min(n, k);
        for (int i = 0; i < n; i ++) {
            while (!q.empty() && q.top().first <= w) {
                m.push(q.top().second);
                q.pop();
            }
            if (!m.empty()) {
                w += m.top();
                m.pop();
            }
            else
                break;
        }
        return w;
    }
};

// 执行用时：252 ms, 在所有 C++ 提交中击败了17.00%的用户
// 内存消耗：80 MB, 在所有 C++ 提交中击败了20.67%的用户