class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        if (firstList.size() == 0 || secondList.size() == 0)
            return {};
        vector<vector<int>> res;
        int f = 0, s = 0;
        while (f < firstList.size() && s < secondList.size()) {
            auto a = firstList[f];
            auto b = secondList[s];
            // case 1
            if (b[1] < a[0]) {
                s++;
                continue;
            }
            // case 2
            if (b[1] == a[0]) {
                res.push_back({a[0], a[0]});
                s++;
                continue;
            }
            // case 3
            if (b[0] < a[0] && b[1] > a[0] && b[1] <= a[1]) {
                res.push_back({a[0], b[1]});
                s++;
                continue;
            }
            // case 4
            if (b[0] < a[0] && b[1] >= a[1]) {
                res.push_back({a[0], a[1]});
                f++;
                continue;
            }
            // case 5
            if (a[0] <= b[0] && a[1] >= b[1]) {
                res.push_back({b[0], b[1]});
                s++;
                continue;
            }
            // case 6
            if (a[0] <= b[0] && b[1] > a[1] && b[0] <= a[1]) {
                res.push_back({b[0], a[1]});
                f++;
                continue;
            }
            // case 7
            if (b[0] > a[0] && b[0] < a[1]) {
                res.push_back({b[0], a[1]});
                f++;
                continue;
            }
            // case 8
            if (a[1] == b[0]) {
                res.push_back({b[0], b[0]});
                f++;
                continue;
            }
            // case 9
            if (a[1] < b[0]) {
                f++;
                continue;
            }
        }
        return res;
    }
};

// 执行用时： 40 ms , 在所有 C++ 提交中击败了 19.31% 的用户
// 内存消耗： 20.2 MB , 在所有 C++ 提交中击败了 5.54% 的用户
