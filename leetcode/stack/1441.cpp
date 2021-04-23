class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string> v;
        int tmp = 1;
        
        for (auto& i : target) {
            while (tmp != i) {
                v.push_back("Push");
                v.push_back("Pop");
                tmp ++;
            }
            v.push_back("Push");
            tmp ++;
        }
        
        return v;
    }
};

// 执行用时：0 ms, 在所有 C++ 提交中击败了100.00%的用户
// 内存消耗：7.7 MB, 在所有 C++ 提交中击败了6.31%的用户