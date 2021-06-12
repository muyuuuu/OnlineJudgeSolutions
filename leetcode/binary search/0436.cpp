class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        vector<pair<int, int>> arr;
        for (int i = 0; i < intervals.size(); ++i) {
            arr.emplace_back(make_pair(intervals[i][0], i));
        }
        sort(arr.begin(), arr.end());
        vector<int> result;
        for (int i = 0; i < intervals.size(); ++i) {
            result.push_back(findFirstBig(arr, intervals[i][1]));
        }
        return result;
    }

    int findFirstBig(vector<pair<int, int>>& arr, int num) {
        int left = 0, right = arr.size();
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (arr[mid].first >= num) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        if (left == arr.size()) return -1;
        return arr[left].second;
    }
};

// 执行用时：72 ms, 在所有 C++ 提交中击败了91.78%的用户
// 内存消耗：24.8 MB, 在所有 C++ 提交中击败了84.42%的用户