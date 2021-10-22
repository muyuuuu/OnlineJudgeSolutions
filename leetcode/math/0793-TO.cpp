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

    long leftbound(int left, long right, int k) {
        while (left <= right) {
            long mid = left + (right - left) / 2;
            if (calc(mid) < k) {
                left = mid + 1;
            }
            else if (calc(mid) > k) {
                right = mid - 1;
            }
            else if (calc(mid) == k) {
                right = mid - 1;
            }
        }
        return left;
    }

    long rightbound(int left, long right, int k) {
        while (left <= right) {
            long mid = left + (right - left) / 2;
            if (calc(mid) < k) {
                left = mid + 1;
            }
            else if (calc(mid) > k) {
                right = mid - 1;
            }
            else if (calc(mid) == k) {
                left = mid + 1;
            }
        }
        return left - 1;
    }

    int preimageSizeFZF(int k) {
        int left = 0;
        long right = LONG_MAX;
        long l = leftbound(left, right, k);
        long r = rightbound(left, right, k);
        return r - l + 1;
    }
};
