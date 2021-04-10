class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int idx{1};
        unordered_map<string, int> m;
        vector<vector<string> > ans;
        ans.resize(strs.size());
        
        for (auto& i : strs){
            string s = i;
            sort(s.begin(), s.end());
            if (m[s] == 0){
                m[s] = idx;
                idx++;
            }
            ans[m[s] - 1].push_back(i);
        }
        ans.erase(ans.begin() + idx - 1, ans.end());
        return ans;
    }
};

// 执行用时：32 ms, 在所有 C++ 提交中击败了95.76%的用户
// 内存消耗：15.7 MB, 在所有 C++ 提交中击败了98.18%的用户