class Solution {
public:
    int maximumScore(int a, int b, int c) {
        priority_queue<int> q;
        q.push(a);
        q.push(b);
        q.push(c);
        int d, e, cnt{0};
        while (q.size() > 1) {
            cnt ++;
            d = q.top();
            q.pop();
            
            e = q.top();
            q.pop();
            if (d - 1 != 0)
                q.push(d - 1);
            if (e - 1 != 0)
                q.push(e - 1);
        }
        return cnt;
    }
};

// 执行用时：124 ms, 在所有 C++ 提交中击败了13.52%的用户
// 内存消耗：5.9 MB, 在所有 C++ 提交中击败了14.19%的用户