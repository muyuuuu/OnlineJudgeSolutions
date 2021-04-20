class Solution {
public:
    struct node{
        int idx;
        int val;
    };
    node t;
    static bool cmp(node a, node b){
        return a.val > b.val;
    }
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<node> ans;
        vector<int> res;
        map<int, int> m;
        int len = nums.size();
        for (int i = 0; i < len; i++){
            if (m[nums[i]] != 0)
                m[nums[i]] += 1;
            else
                m[nums[i]] = 1;
        }
        for (auto it = m.begin(); it != m.end(); it++){
            t.idx = it->first;
            t.val = it->second;
            ans.push_back(t);
        }
        sort(ans.begin(), ans.end(), cmp);
        for (int i = 0; i < k; i++){
            res.push_back(ans[i].idx);
        }
        return res;
    }
};

// 执行用时：24 ms, 在所有 C++ 提交中击败了34.49%的用户
// 内存消耗：13.6 MB, 在所有 C++ 提交中击败了22.47%的用户