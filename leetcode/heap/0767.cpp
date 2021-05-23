class Solution {
private:
    bool static cmp (const pair<int, int>& a, const pair<int, int>& b) {
        return a.second > b.second; // 按照频率从大到小排序
    }
public:
    string reorganizeString(string S) {
        unordered_map<char, int> umap;
        int maxFreq = 0;
        
        for (char s : S) {
            umap[s]++;
            maxFreq = max(umap[s], maxFreq);
        }
        
        // 如果最大频率超过一半多，无法重构
        if (2 * maxFreq - 1 > S.size()) 
            return "";

        vector<pair<int, int>> vec(umap.begin(), umap.end());
        // 给频率排个序
        sort(vec.begin(), vec.end(), cmp); 

        string result(S);
        int index = 0;
        // 先按奇数位散开
        for (int i = 0; i < vec.size(); i++) {
            while (vec[i].second--) {
                result[index] = vec[i].first;
                index += 2;
                // 奇数位插满了插偶数位
                if (index >= S.size()) 
                    index = 1; 
            }
        }
        return result;
    }
};

// 执行用时：4 ms, 在所有 C++ 提交中击败了47.88%的用户
// 内存消耗：6.2 MB, 在所有 C++ 提交中击败了38.75%的用户