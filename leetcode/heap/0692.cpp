class Solution {
private:
    struct node {
        int num = 0;
        string w;
    };
public:
    static bool cmp(node a, node b) {
        // 按出现的次数排序  
        if (a.num > b.num)
            return true;
        // 次数相等，字母小的在前面
        else if (a.num == b.num)
            return a.w < b.w;
        // 次数小，放到后面
        return false;
    }
    vector<string> topKFrequent(vector<string>& words, int k) {
        
        vector<node> v;
        unordered_map<string, int> m1;
        node tmp;
        
        for (auto& i : words) {
            // 记录出现次数
            if (m1[i] == 0)
                m1[i] = 1;
            else
                m1[i]++;
            
            tmp.num = m1[i];
            tmp.w = i;
            v.push_back(tmp);
        }
        
        sort(v.begin(), v.end(), cmp);
        vector<string> ans;
        int cnt {0};
        m1.clear();
        for (int i = 0; i < v.size(); i++) {
            if (m1[v[i].w] == 0) {
                ans.push_back(v[i].w);
                cnt ++;
                if (cnt >= k)
                    break;
            }
            m1[v[i].w] = 1;
        }
        return ans;
    }
};

// 执行用时：24 ms, 在所有 C++ 提交中击败了9.26%的用户
// 内存消耗：13.2 MB, 在所有 C++ 提交中击败了5.14%的用户