class Solution {
public:
    long calc(long val) {
        long res{0};
        long tmp{5};
        while (tmp <= val) {
            res += val / tmp;
            tmp *= 5;
        }
        return res;
    }

    int preimageSizeFZF(int k) {
        long left = 0;
        long right = LONG_MAX;
        while (left < right) {
            long mid = left + (right - left) / 2;
            long tmp = calc(mid);
            if (tmp == k) {
                return 5;
            }
            else if (tmp < k)
                left = mid + 1;
            else if (tmp > k)
                right = mid;
        }
        return 0;
    }
};

// 执行用时： 0 ms , 在所有 C++ 提交中击败了 100.00% 的用户
// 内存消耗： 5.8 MB , 在所有 C++ 提交中击败了 89.21% 的用户
