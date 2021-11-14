class Solution {
public:
  int findCheapestPrice(int n, vector<vector<int>> &flights, int src, int dst,
                        int k) {
    int res{-1};
    unordered_map<int, unordered_map<int, int>> path;
    for (auto item : flights) {
      path[item[0]][item[1]] = item[2];
    }
    vector<int> dis(n, INT_MAX);
    dis[src] = 0;
    queue<pair<int, int>> q;
    q.emplace(src, 0);

    while (q.size() && k >= -1) {
      int size = q.size();
      for (int i = 0; i < size; i++) {
        auto [pre, dis1] = q.front();
        q.pop();

        if (pre == dst && (res == -1 || res > dis1)) {
          res = dis1;
          continue;
        }

        for (auto [next, dis2] : path[pre]) {
          if (dis[next] > dis2 + dis1) {
            dis[next] = dis1 + dis2;
            q.emplace(next, dis1 + dis2);
          }
        }
      }
      k--;
    }

    return res;
  }
};

// 执行用时： 28 ms , 在所有 C++ 提交中击败了 76.49% 的用户
// 内存消耗： 13.9 MB , 在所有 C++ 提交中击败了 16.94% 的用户
