class Solution {
private:
    vector<int> visited;
    vector<int> res;
    vector<vector<int>> edge;
    bool cycle{false};
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        visited.assign(numCourses, 0);
        edge.resize(numCourses);

        for (auto& node : prerequisites){
            edge[node[1]].push_back(node[0]);
        }

        for (int i = 0; i < numCourses && !cycle; i++) {
            if (visited[i] == 0)
                dfs(i, edge);
        }

        if (cycle == true)
            return {};
        else {
            reverse(res.begin(), res.end());
        }
        return res;
    }

    void dfs(int idx, vector<vector<int>>& edge) {
        visited[idx] = 1;

        for (auto& i : edge[idx]) {
            if (visited[i] == 1) {
                cycle = true;
                return;
            }
            else if (visited[i] == 0)
                dfs(i, edge);
        }

        visited[idx] = 2;
        res.push_back(idx);
    }
};

// 执行用时： 20 ms , 在所有 C++ 提交中击败了 78.92% 的用户
// 内存消耗： 13.8 MB , 在所有 C++ 提交中击败了 36.71% 的用户
