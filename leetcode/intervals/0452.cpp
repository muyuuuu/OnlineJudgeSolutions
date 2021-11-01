class Solution {
public:

    static bool cmp (vector<int>& v1, vector<int>& v2) {
        return v1[1] < v2[1];
    }

    int findMinArrowShots(vector<vector<int>>& points) {

        if (points.size() == 1)
            return 1;

        sort(points.begin(), points.end(), cmp);

        int end{INT_MIN}, s, res{0};

        for (auto& i : points) {
            s = i[0];
            if (s > end) {
                res++;
                end = i[1];
            }
        }

        return res;
    }
};

// 执行用时： 508 ms , 在所有 C++ 提交中击败了 20.29% 的用户
// 内存消耗： 87.7 MB , 在所有 C++ 提交中击败了 29.04% 的用户
