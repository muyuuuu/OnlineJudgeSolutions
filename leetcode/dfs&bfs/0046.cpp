class Solution {
public:
    vector<vector<int>> res;
    vector<int> tmp;
    unordered_map<int, int> m;
    const int v{32};

    vector<vector<int>> permute(vector<int>& nums) {
        int cnt{0};
        dfs(tmp, nums);
        return res;
    }

    void dfs(vector<int>& tmp, vector<int>& nums) {
        if (tmp.size() == nums.size()) {
            res.push_back(tmp);
        }

        for (int i = 0; i < nums.size(); i++) {
            if (m.count(nums[i])) {
                continue;
            }
            else {
                m[nums[i]] = v;
                tmp.push_back(nums[i]);
                dfs(tmp, nums);
                tmp.pop_back();
                m.erase(nums[i]);
            }
        }
    }
};

// 执行用时： 8 ms , 在所有 C++ 提交中击败了 12.14% 的用户
// 内存消耗： 8 MB , 在所有 C++ 提交中击败了 16.22% 的用户
