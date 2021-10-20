class Solution {
public:
    bool isPowerOfTwo(int n) {
        if (n <= 0)
            return false;
        if ((n&(n-1)) == 0)
            return true;
        return false;
    }
};

// 执行用时： 0 ms , 在所有 C++ 提交中击败了 100.00% 的用户
// 内存消耗： 5.6 MB , 在所有 C++ 提交中击败了 98.22% 的用户
