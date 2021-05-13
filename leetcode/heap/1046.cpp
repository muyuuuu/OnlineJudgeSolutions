class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> q;
        for (auto& i : stones) {
            q.push(i);
        }
        int a, b;
        while (q.size() > 1) {
            a = q.top();
            q.pop();
            b = q.top();
            q.pop();
            if (a > b)
                q.push(a - b);
        }
        return q.empty() ? 0 : q.top();
    }
};

// 执行用时：0 ms, 在所有 C++ 提交中击败了100.00%的用户
// 内存消耗：6 MB, 在所有 C++ 提交中击败了73.12%的用户