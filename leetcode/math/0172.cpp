class Solution {
public:
    int trailingZeroes(int n) {
        int res{0};
        long tmp = 5;
        while (tmp <= n) {
            res += (n / tmp);
            tmp *= 5;
        }
        return res;
    }
};

// 执行用时： 4 ms , 在所有 C++ 提交中击败了 47.67% 的用户
// 内存消耗： 5.9 MB , 在所有 C++ 提交中击败了 41.13% 的用户
