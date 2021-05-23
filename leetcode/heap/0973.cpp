// class Solution {
// private:
//     struct node {
//         vector<int> co;
//         int dis;
//     };
// public:
//     static bool cmp(node a, node b) {
//         return a.dis < b.dis;   
//     }
//     vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
//         node tmp;
//         int d;
//         vector<node> ans;
//         for (auto& i : points) {
//             tmp.co = i;
//             tmp.dis = pow(i[0], 2) + pow(i[1], 2);
//             ans.push_back(tmp);
//         }
//         sort(ans.begin(), ans.end(), cmp);
//         ans.erase(ans.begin() + k, ans.end());
//         vector<vector<int> >res;
//         for (auto&i : ans) {
//             res.push_back(i.co);
//         }
//         return res;
//     }
// };

// 执行用时：1296 ms, 在所有 C++ 提交中击败了5.78%的用户
// 内存消耗：215.4 MB, 在所有 C++ 提交中击败了5.06%的用户

// https://www.cnblogs.com/huashanqingzhu/p/11040390.html

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int, int> > q;
        for (int i = 0; i < k; i++) {
            q.emplace(pow(points[i][0], 2) + pow(points[i][1], 2), i);
        }
        for (int i = k; i < points.size(); i++) {
            if (pow(points[i][0], 2) + pow(points[i][1], 2) < q.top().first) {
                q.pop();
                q.emplace(pow(points[i][0], 2) + pow(points[i][1], 2), i);
            }
        }
        vector<vector<int> > ans;
        while (!q.empty()) {
            ans.push_back(points[q.top().second]);
            q.pop();
        }
        return ans;
    }
};

// 执行用时：192 ms, 在所有 C++ 提交中击败了70.66%的用户
// 内存消耗：52 MB, 在所有 C++ 提交中击败了54.55%的用户