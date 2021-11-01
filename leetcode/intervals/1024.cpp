class Solution {
public:

    static bool cmp(vector<int>& v1, vector<int>& v2) {
        return v1[0] < v2[0];
    }

    int videoStitching(vector<vector<int>>& clips, int time) {

        if (time == 0)
            return 0;

        int res{0}, start{0}, i{0}, len{-1}, end{-1}, s1;
        sort(clips.begin(), clips.end(), cmp);

        while (i < clips.size() && clips[i][0] <= start) {
            while (i < clips.size() && clips[i][0] <= start) {
                end = max(end, clips[i][1]);
                // cout << end << endl;
                i++;
            }

            res++;
            if (end >= time)
                return res;
            start = end;
        }

        return -1;
    }
};

// 执行用时： 0 ms , 在所有 C++ 提交中击败了 100.00% 的用户
// 内存消耗： 7.5 MB , 在所有 C++ 提交中击败了 88.25% 的用户
