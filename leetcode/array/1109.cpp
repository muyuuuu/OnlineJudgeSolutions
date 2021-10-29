class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int> res(n, 0);
        for (auto item : bookings) {
            res[item[0] - 1] += item[2];
            if (item[1] < n)
                res[item[1]] -= item[2];
        }
        for (int i = 1; i < res.size(); i++) {
            res[i] += res[i-1];
        }
        return res;
    }
};

// 执行用时： 204 ms , 在所有 C++ 提交中击败了 34.12% 的用户
// 内存消耗： 72.3 MB , 在所有 C++ 提交中击败了 21.17% 的用户
