class Solution {
public:
    vector<vector<int>> res;
    vector<int> tmp;

    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        tmp.push_back(0);
        build(0, graph, graph.size() - 1);
        return res;
    }

    void build(int idx, vector<vector<int>>& graph, int n) {
        if (idx == n) {
            res.push_back(tmp);
            return;
        }

        for (auto& i : graph[idx]) {
            tmp.push_back(i);
            build(i, graph, n);
            tmp.pop_back();
        }
    }
};

// 执行用时： 16 ms , 在所有 C++ 提交中击败了 48.21% 的用户
// 内存消耗： 11.7 MB , 在所有 C++ 提交中击败了 55.71% 的用户
