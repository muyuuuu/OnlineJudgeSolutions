class Solution {
public:

    static bool cmp(vector<int>& v1, vector<int>& v2) {
        return v1[1] < v2[1];
    }

    int eraseOverlapIntervals(vector<vector<int>>& intervals) {

        sort(intervals.begin(), intervals.end(), cmp);
        int res{0}, end{INT_MIN}, s1{0}, s2{0};

        for (auto& item : intervals) {
            s1 = item[0];
            if (end  <= s1) {
                res ++;
                end = item[1];
            }
        }

        return intervals.size() - res;
    }
};

// 执行用时： 404 ms , 在所有 C++ 提交中击败了 24.62% 的用户
// 内存消耗： 87.8 MB , 在所有 C++ 提交中击败了 15.11% 的用户
