class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> m;
        int s2 = nums2.size();
        m[nums2[s2 - 1]] = -1;
        bool flag{false};
        for (int i = 0; i < s2 - 1; i++) {
            flag = false;
            for (int j = i + 1; j < s2; j++) {
                if (nums2[j] > nums2[i]) {
                    flag = true;
                    m[nums2[i]] = nums2[j];
                    break;
                }
            }
            if (flag == false)
                m[nums2[i]] = -1;
        }
        vector<int> res;
        for (auto& i : nums1) {
            res.push_back(m[i]);
        }
        return res;
    }
};

// 执行用时：8 ms, 在所有 C++ 提交中击败了60.74%的用户
// 内存消耗：8.7 MB, 在所有 C++ 提交中击败了38.31%的用户