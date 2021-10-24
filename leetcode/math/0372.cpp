class Solution {
public:

    int mypow(int a, int k) {
        int res = 1;
        a %= 1337;
        res %= 1337;
        for (int i = 0; i < k; i++) {
            res *= a;
            res %= 1337;
        }
        return res;
    }

    int superPow(int a, vector<int>& b) {
        if (b.empty())
            return 1;
        int k = b.back();
        b.pop_back();
        int res1 = mypow(a, k);
        int res2 = mypow(superPow(a, b), 10);
        return (res1 * res2) % 1337;
    }
};

// 执行用时： 12 ms , 在所有 C++ 提交中击败了 59.87% 的用户
// 内存消耗： 11.5 MB , 在所有 C++ 提交中击败了 18.36% 的用户
