class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int> tmp;
        vector<int> res;
        res.resize(nums.size());
        stack<int> s;

        tmp.resize(nums.size());
        tmp.assign(nums.begin(), nums.end());
        tmp.insert(tmp.end(), nums.begin(), nums.end());

        for (int i = tmp.size() - 1; i > nums.size() - 1; i-- ) {
            while (!s.empty() && tmp[i] > s.top()) {
                s.pop();
            }
            s.push(tmp[i]);
        }

        for (int i = nums.size() - 1; i >= 0; i--) {
            while (!s.empty() && nums[i] >= s.top()) {
                s.pop();
            }
            if (s.empty())
                res[i] = -1;
            else
                res[i] = s.top();
            s.push(nums[i]);
        }
    
        return res;
    }
};

// 执行用时： 32 ms , 在所有 C++ 提交中击败了 75.19% 的用户
// 内存消耗： 24.8 MB , 在所有 C++ 提交中击败了 9.32% 的用户
