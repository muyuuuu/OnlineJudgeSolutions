class Solution {
public:
    int getTime(vector<int>& piles, int m, int h) {
        int t{0};
        for (auto& i : piles){
            if (i % m == 0)
                t += i / m;
            else
                t += (i / m + 1);
        }
        if (t > h)
            return 0;
        return m;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        if (piles.size() == 1) {
            if (piles[0] % h == 0)
                return piles[0] / h;
            else
                return (piles[0] / h + 1);
        }
        sort(piles.begin(), piles.end());
        int l = 1, n = piles.size();
        int r = piles[n-1], m;
        int maxv = 1000000005;
        while (l <= r) {
            m = l + (r - l) / 2;
            auto v = getTime(piles, m, h);
            if (v) {
                if (v < maxv) {
                    maxv = v;
                }
                r = m - 1;
            }
            else {
                l = m + 1;
            }
        }
        return maxv;
    }
};

// 执行用时：44 ms, 在所有 C++ 提交中击败了86.07%的用户
// 内存消耗：18.4 MB, 在所有 C++ 提交中击败了24.55%的用户