class Solution {
private:
    int sz;
    unordered_map<int, int> mapping;
public:
    Solution(int N, vector<int>& blacklist) {
        sz = N - blacklist.size();
        for (int b : blacklist) { 
            mapping[b] = 666;
        }
        int last = N - 1;
        for (int b : blacklist) {
            if (b >= sz) {
                continue;
            }
            while (mapping.count(last)) {
                last--;
            }
            mapping[b] = last;
            last--;
        }
    }
    
    int pick() {
        int index = rand() % sz;
        if (mapping.count(index)) {
            return mapping[index];
        }
        return index;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(n, blacklist);
 * int param_1 = obj->pick();
 */

// 执行用时： 140 ms , 在所有 C++ 提交中击败了 36.31% 的用户
// 内存消耗： 68.6 MB , 在所有 C++ 提交中击败了 74.52% 的用户
