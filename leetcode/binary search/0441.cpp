class Solution {
public:
    int arrangeCoins(int n) {
        long long cnt = 1, res = 0, sum = 0;
        for (int i = 0; i < n; i++) {
            sum += cnt;
            cnt++;
            if (sum <= n)
                res = i + 1;
            else
                return res;
        }
        return res;
    }
};

// 执行用时：12 ms, 在所有 C++ 提交中击败了34.30%的用户
// 内存消耗：5.8 MB, 在所有 C++ 提交中击败了56.67%的用户