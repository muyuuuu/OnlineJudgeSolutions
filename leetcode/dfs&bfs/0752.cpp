class Solution {
public:

    void up(string& s, int i) {
        if (s[i] == '9')
            s[i] = '0';
        else {
            s[i] += 1;
        }
    }

    void down(string& s, int i) {
        if (s[i] == '0')
            s[i] = '9';
        else {
            s[i] -= 1;
        }
    }

    int openLock(vector<string>& deadends, string target) {
        unordered_map<string, int> dead;
        for (auto i : deadends)
            dead[i] = 1;
        unordered_map<string, int> visited;
        deque<string> q;
        q.push_back("0000");
        visited["0000"] = 1;
        int cnt = 0;
        while (!q.empty()) {
            int s = q.size();
            for (int i = 0; i < s; i++) {
                string node = q.front();
                q.pop_front();
                
                if (node == target)
                    return cnt;
                // 因为一开始的 0000 可能是dead，所以必须在外部判断
                if (dead.count(node))
                    continue;

                for (int i = 0; i < 4; i++) {
                    up(node, i);
                    // 这里判断是错误的，因为已经操作了 dead
                    if (!visited[node]) {
                        q.push_back(node);
                        visited[node] = 1;
                    }
                    down(node, i);
                    down(node, i);
                    if (!visited[node]) {
                        q.push_back(node);
                        visited[node] = 1;
                    }
                    up(node, i);
                }
            }
            cnt ++;
        }

        return -1;
    }
};

// 执行用时： 172 ms , 在所有 C++ 提交中击败了 51.51% 的用户
// 内存消耗： 40.2 MB , 在所有 C++ 提交中击败了 24.45% 的用户
