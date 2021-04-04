class Solution {
public:
    struct node{
        int num;
        char c;
    };
    static bool cmp(node a, node b) {return a.num > b.num;}
    string frequencySort(string s) {
        unordered_map<char, int> m;
        node t;
        vector<node> ans;
        string res;
        for (auto &i : s){
            m[i]++;
        }
        for (auto &it : m){
            t.num = it.second;
            t.c = it.first;
            ans.push_back(t);
        }
        sort(ans.begin(), ans.end(), cmp);
        for (auto &it : ans){
            for (auto i = 0; i < it.num; i++){
                res += it.c;
            }
        }
        return res;
    }
};

// 执行用时：8 ms, 在所有 C++ 提交中击败了93.96%的用户
// 内存消耗：8.3 MB, 在所有 C++ 提交中击败了79.59%的用户