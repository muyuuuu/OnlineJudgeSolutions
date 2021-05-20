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

class Solution 
{
public:
    int findMaximizedCapital(int k, int W, vector<int>& Profits, vector<int>& Capital) 
    {
        int n = Profits.size();
        priority_queue<int> q2;    //当前可以得到的利润，大根堆
        // 门槛，可获得的利润，小根堆
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> q1;
        for (int i = 0; i < n; i++)
        {
            q1.push(pair<int,int>(Capital[i], Profits[i]));
        }
        for (int ee = 0; ee < min(n, k); ee ++)
        {
            while (q1.size() && q1.top().first <= W)
            {
                q2.push(q1.top().second); //能开的项目，利润都记下来待选
                q1.pop();
            }
            if (q2.size())
            {
                W += q2.top();   //当前能获得的，最大的利润
                q2.pop();
            }
            else
            {
                break;  //当前没有可以开的项目
            }
        }
        return W;
    }
};

// 执行用时：252 ms, 在所有 C++ 提交中击败了17.00%的用户
// 内存消耗：80 MB, 在所有 C++ 提交中击败了20.67%的用户