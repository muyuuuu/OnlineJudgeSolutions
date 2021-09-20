class Solution {
public:
    int check(int m, int days, vector<int>& weights) {
        int d{0};

        for (int i = 0; i < weights.size(); ) {
            int cap = m;
            while (i < weights.size()) {
                if (cap < weights[i]) {
                    break;
                }
                else {
                    cap -= weights[i];
                }
                i++;
            }
            d++;
        }

        if (d > days)
            return -1;
        return m;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        int l{-1};
        for (auto& i : weights)
            if (i > l)
                l = i;
        int r = 0;
        int res = INT_MAX;
        for (auto& i : weights) {
            r += i;
        }

        while (l <= r) {
            int m = l + (r - l) / 2;
            int t = check(m, days, weights);

            if (t == -1) {
                l = m + 1;
            }
            else {
                r = m - 1;
                if (m < res)
                    res = m;
            }
        }

        return res;
    }
};

// 执行用时： 56 ms , 在所有 C++ 提交中击败了 52.57% 的用户
// 内存消耗： 25.5 MB , 在所有 C++ 提交中击败了 21.96% 的用户
