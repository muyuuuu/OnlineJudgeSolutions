class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        int len1 = nums1.size(), idx1{0};
        int len2 = nums2.size(), idx2{0};
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        vector<int> ans;
        int a, b;
        while (idx1 < len1 && idx2 < len2) {
            a = nums1[idx1], b = nums2[idx2];
            if (a == b) {
                if (!ans.size() || a != ans.back()) {
                    ans.push_back(a);
                }
                idx1++;
                idx2++;
            }
            else if (a < b)
                idx1++;
            else
                idx2++;
        }
        return ans;
    }
};

// 执行用时：4 ms, 在所有 C++ 提交中击败了94.11%的用户
// 内存消耗：9.7 MB, 在所有 C++ 提交中击败了89.67%的用户