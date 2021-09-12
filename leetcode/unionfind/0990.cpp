class Solution {
private:
    vector<string> eq;
    vector<string> neq;
    vector<int> parent;
public:
    bool equationsPossible(vector<string>& equations) {
        for (auto& i : equations) {
            if (i[1] == '!')
                neq.push_back(i);
            else
                eq.push_back(i);
        }

        parent.resize(26);

        for (int i = 0; i < 26; i++)
            parent[i] = i;

        for (auto& i : eq) {
            union_(find(i[0] - 'a'), find(i[3] - 'a'));
        }

        bool res{true};
        for (auto& i : neq) {
            if (!satis(find(i[0] - 'a'), find(i[3] - 'a'))) {
                res = false;
                break;
            }
        }

        return res;
    }

    void union_(int a, int b) {
        int p1 = find(a);
        int p2 = find(b);
        if (p1 != p2)
            parent[p1] = p2;
    }

    int find(int x) {
        while (x != parent[x]) {
            parent[x] = parent[parent[x]];
            x = parent[x];
        }
        return x;
    }

    bool satis(int a, int b) {
        int p1 = find(a);
        int p2 = find(b);
        if (p1 == p2)
            return false;
        return true;
    }
};

// 执行用时： 0 ms , 在所有 C++ 提交中击败了 100.00% 的用户
// 内存消耗： 11.9 MB , 在所有 C++ 提交中击败了 5.05% 的用户
