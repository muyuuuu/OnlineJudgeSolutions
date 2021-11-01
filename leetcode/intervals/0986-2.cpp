class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        int f = 0, s = 0;
        vector<vector<int>> res;
        while (f < firstList.size() && s < secondList.size()) {
            int l = max(firstList[f][0], secondList[s][0]);
            int r = min(firstList[f][1], secondList[s][1]);
            if (l <= r) {
                res.push_back({l, r});
            }
            // cout << f << "--" << s << endl;
            if (firstList[f][1] < secondList[s][1])
                f++;
            else
                s++;
        }
        return res;
    }
};

// 执行用时： 28 ms , 在所有 C++ 提交中击败了 80.45% 的用户
// 内存消耗： 18.1 MB , 在所有 C++ 提交中击败了 89.86% 的用户
