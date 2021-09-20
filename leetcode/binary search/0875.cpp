class Solution {
public:

    int check(int m, vector<int>& piles, int h) {
        int sum{0};
        for (auto& i : piles) {
            if (i % m == 0 && i / m == 0)
                sum += 1;
            else if (i % m == 0) {
                sum += (i / m);
            }
            else
                sum += (i / m + 1);
        }

        if (sum <= h)
            return 1;
        return 0;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        sort(piles.begin(), piles.end());
        int l = 1;
        int r = *(piles.end() - 1);
        int res = INT_MAX;

        while (l <= r) {
            int m = l + (r - l) / 2;
            int t = check(m, piles, h);
            if (t == 0) {
                l = m + 1;
            }
            else if (t == 1) {
                if (m < res) {
                    res = m;
                }
                r = m - 1;
            }
        }

        return res;
    }
};

// 执行用时： 44 ms , 在所有 C++ 提交中击败了 50.07% 的用户
// 内存消耗： 18.4 MB , 在所有 C++ 提交中击败了 40.18% 的用户
