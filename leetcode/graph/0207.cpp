class Solution {
private:
    vector<vector<int>> edge;
    vector<int> visited;
    bool res{true};
public:

    void dfs(int idx, vector<vector<int>>& edge, vector<int>& visited) {

        visited[idx] = 1;
        for (auto& i : edge[idx]) {
            if (visited[i] == 0)
                dfs(i, edge, visited);
            else if (visited[i] == 1) {
                res = false;
                return;
            }
        }
        // 表示这个节点没问题
        visited[idx] = 2;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        edge.resize(numCourses);
        visited.assign(numCourses, 0);

        for (auto& node : prerequisites) {
            edge[node[0]].push_back(node[1]);
        }

        for(int i = 0; i < numCourses && res; i++) {
            if (visited[i] == 0)
                dfs(i, edge, visited);
        }

        return res;
    }
};

// 执行用时： 20 ms , 在所有 C++ 提交中击败了 79.01% 的用户
// 内存消耗： 13.5 MB , 在所有 C++ 提交中击败了 50.36% 的用户
