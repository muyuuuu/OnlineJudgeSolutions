/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is lower than the guess number
 *			      1 if num is higher than the guess number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        int l = 1, r = n;
        int mid;
        while (l <= r) {
            mid = l + (r - l) / 2;
            if (0 == guess(mid))
                return mid;
            else if (guess(mid) < 0)
                r = mid - 1;
            else 
                l = mid + 1;
        }
        return mid;
    }
};

// 执行用时：0 ms, 在所有 C++ 提交中击败了100.00%的用户
// 内存消耗：5.9 MB, 在所有 C++ 提交中击败了11.92%的用户