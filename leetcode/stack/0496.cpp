class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res;

        vector<int> v1;
        v1.resize(10005);

        stack<int> s;
        for (int i = nums2.size() - 1; i >= 0; i--) {
            while (!s.empty() && nums2[i] > s.top()) {
                s.pop();
            }
            if (s.empty())
                v1[nums2[i]] = -1;
            else
                v1[nums2[i]] = s.top();
            s.push(nums2[i]);
        }

        for (int i = 0; i < nums1.size(); i++) {
            res.push_back(v1[nums1[i]]);
        }

        return res;
    }
};

// 执行用时： 4 ms , 在所有 C++ 提交中击败了 92.99% 的用户
// 内存消耗： 8.9 MB , 在所有 C++ 提交中击败了 5.10% 的用户
