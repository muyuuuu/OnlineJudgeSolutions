class Solution {
private:
    struct node {
        double p;
        double t;
        bool operator<(const node& a) const{
            return ((p+1) / (t+1) - p/t) < ((a.p+1) / (a.t+1) - a.p/a.t);
        }
    };
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        int n = classes.size();
        priority_queue< node > q;
        node tmp;
        for (int i = 0; i < n; i++) {
            tmp.p = classes[i][0];
            tmp.t =  classes[i][1];
            q.push(tmp);
        }
        for (int i = 0; i < extraStudents; i++) {
            auto t = q.top();
            q.pop();
            t.p += 1;
            t.t += 1;
            q.push(t);
        }
        double res{0};
        while (!q.empty()) {
            res += q.top().p / q.top().t;
            q.pop();
        }
        return res / n;
    }
};

// 执行用时：1252 ms, 在所有 C++ 提交中击败了17.35%的用户
// 内存消耗：91.1 MB, 在所有 C++ 提交中击败了67.00%的用户