class Solution {
public:
    int minAbsoluteSumDiff(vector<int>& nums1, vector<int>& nums2) {
        set<int> s;
        int n = nums1.size();
        long long res1 = 0, res2 = 0;
        for (int i = 0; i < n; i++){
            s.insert(nums1[i]);
            res1 += abs(nums1[i] - nums2[i]);
        }
        for (int i = 0; i < n; i++) {
            auto it = s.lower_bound(nums2[i]);
            long long cur = abs(nums1[i] - nums2[i]);
            if (it != s.end()) {
                res2 = max(res2, cur - abs(*it - nums2[i]));
            }
            if (it != s.begin()) {
                it--;
                res2 = max(res2, cur - abs(*(it) - nums2[i]));
            }
        }
        int m = 1e9 + 7;
        return (res1 - res2) % (m);
    }
};

// 执行用时：272 ms, 在所有 C++ 提交中击败了61.93%的用户
// 内存消耗：73 MB, 在所有 C++ 提交中击败了83.18%的用户