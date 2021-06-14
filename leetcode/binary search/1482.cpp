class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        if (m * k > bloomDay.size())
            return -1;
        int n = bloomDay.size(), l = INT_MAX, r = -1, mid;
        for (auto& i : bloomDay) {
            l = min(l, i);
            r = max(r, i);
        }
        while (l <= r) {
            mid = l + (r - l) / 2;
            if (canMake(bloomDay, mid, m, k)) {
                r = mid - 1;
            }
            else
                l = mid + 1;
        }
        return l;
    }
    bool canMake(vector<int>& bloomDay, int mid, int m, int k) {
        int f{0}, res{0};
        for (auto & i : bloomDay) {
            if (i <= mid) {
                f++;
                if (f == k) {
                    res++;
                    f = 0;
                }
            }
            else
                f = 0;
        }
        return res >= m;
    }
};

// 执行用时：136 ms, 在所有 C++ 提交中击败了98.72%的用户
// 内存消耗：61.8 MB, 在所有 C++ 提交中击败了27.02%的用户