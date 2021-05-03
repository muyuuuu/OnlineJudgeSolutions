class Solution {
public:
    vector<int> mostCompetitive(vector<int>& nums, int k) {
        vector<int> st;
        int cnt = nums.size() - k;
        for (auto& i : nums) {
            if (st.empty()) 
                st.push_back(i);
            else {
                while (!st.empty() && i < st.back() && cnt > 0) {
                    cnt--;
                    st.pop_back();
                }
                st.push_back(i);
            }
        }
        while (cnt > 0) {
            st.pop_back();
            cnt--;
        }
        return st;
    }
};

// 执行用时：192 ms, 在所有 C++ 提交中击败了93.77%的用户
// 内存消耗：108.6 MB, 在所有 C++ 提交中击败了43.64%的用户