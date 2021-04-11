class Solution {
public:
    vector<vector<int>> pairSums(vector<int>& nums, int target) {
        unordered_map<int, int> m;
        vector<vector<int> > v;
        vector<int> v1;
        for(auto& i : nums){
            if(m[target - i] > 0){
                v1.push_back(target - i);
                v1.push_back(i);
                v.push_back(v1);
                m[target - i]--;
                v1.clear();
            }
            else{
                m[i]++;
            }
        }
        return v;
    }
};

// 执行用时：164 ms, 在所有 C++ 提交中击败了61.62%的用户
// 内存消耗：58.1 MB, 在所有 C++ 提交中击败了42.02%的用户