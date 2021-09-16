class Solution {
private:
    using PII = pair<int, int>;
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {

        stack<PII> s;
        vector<int> res;
        res.resize(temperatures.size());

        for (int i = temperatures.size() - 1; i >= 0; i--) {
            while (!s.empty() && temperatures[i] >= s.top().first) {
                s.pop();
            }

            if (s.empty())
                res[i] = 0;
            else
                res[i] = s.top().second - i;

            s.push(pair(temperatures[i], i));
        }

        return res;

    }
};

// 执行用时： 160 ms , 在所有 C++ 提交中击败了 42.09% 的用户
// 内存消耗： 83.1 MB , 在所有 C++ 提交中击败了 90.55% 的用户
