class Solution {
public:
    int countPrimes(int n) {
        vector<bool> isPrim(n, true);
        for (int i = 2; i * i < n; i++) {
            if (isPrim[i]) {
                for (int j = 2 * i; j < n; j += i) {
                    isPrim[j] = false;
                }
            }
        }
        int res{0};
        for (int i = 2; i < n; i++) {
            if (isPrim[i])
                res++;
        }
        return res;
    }
};

// 执行用时： 168 ms , 在所有 C++ 提交中击败了 41.17% 的用户
// 内存消耗： 10 MB , 在所有 C++ 提交中击败了 71.44% 的用户
