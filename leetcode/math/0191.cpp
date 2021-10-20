class Solution {
public:
    int hammingWeight(uint32_t n) {
        int res{0};
        while (n != 0) {
            n = n&(n-1);
            res ++;
        }
        return res;
    }
};

// 执行用时： 0 ms , 在所有 C++ 提交中击败了 100.00% 的用户
// 内存消耗： 5.9 MB , 在所有 C++ 提交中击败了 47.81% 的用户
