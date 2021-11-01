class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        int res{0};
        sort(intervals.begin(), intervals.end(), [](vector<int>& v1, vector<int>& v2) {
            if (v1[0] < v2[0])
                return true;
            else if (v1[0] == v2[0])
                return v1[1] > v2[1];
            return false;
        });
        int left = intervals[0][0];
        int right = intervals[0][1];
        for (int i = 1; i < intervals.size(); i++) {
            if (left <= intervals[i][0] && right >= intervals[i][1]) {
                res++;
            }
            else if (intervals[i][0] <= right && intervals[i][1] >= right) {
                left = intervals[i][0];
                right = intervals[i][1];
            }
            else if (intervals[i][0] > right) {
                left = intervals[i][0];
                right = intervals[i][1];
            }
        }
        return intervals.size() - res;
    }
};

// 行用时： 16 ms , 在所有 C++ 提交中击败了 97.36% 的用户
// 内存消耗： 11.1 MB , 在所有 C++ 提交中击败了 53.39% 的用户
