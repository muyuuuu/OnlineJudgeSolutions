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

// class Solution {
// public:
//     vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
//         priority_queue<pair<int, int>> q;
//         for (int i = 0; i < K; ++i) {
//             q.emplace(points[i][0] * points[i][0] + points[i][1] * points[i][1], i);
//         }
//         int n = points.size();
//         for (int i = K; i < n; ++i) {
//             int dist = points[i][0] * points[i][0] + points[i][1] * points[i][1];
//             if (dist < q.top().first) {
//                 q.pop();
//                 q.emplace(dist, i);
//             }
//         }
//         vector<vector<int>> ans;
//         while (!q.empty()) {
//             ans.push_back(points[q.top().second]);
//             q.pop();
//         }
//         return ans;
//     }
// };

// 执行用时：232 ms, 在所有 C++ 提交中击败了47.44%的用户
// 内存消耗：52.1 MB, 在所有 C++ 提交中击败了52.49%的用户