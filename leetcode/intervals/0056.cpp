class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> res;
        sort(intervals.begin(), intervals.end(), [](vector<int>& v1, vector<int>&v2){
            if (v1[0] < v2[0])
                return true;
            else if (v1[0] == v2[0])
                return v1[1] < v2[1];
            return false;
        });
        int left = intervals[0][0];
        int right = intervals[0][1];
        for (int i = 1; i < intervals.size(); i++) {
            auto item = intervals[i];
            if (left == item[0]) {
                right = item[1];
            }
            if (left < item[0]){
                if (right > item[1]) {
                    continue;
                }
                if (right >= item[0]) {
                    right = item[1];
                }
            }
            if (right < item[0]){
                res.push_back({left, right});
                left = item[0];
                right = item[1];
            }
        }
        // if (left > res[res.size() - 1][1])
        res.push_back({left, right});
        return res;
    }
};

// 执行用时： 20 ms , 在所有 C++ 提交中击败了 59.28% 的用户
// 内存消耗： 14.4 MB , 在所有 C++ 提交中击败了 18.44% 的用户
