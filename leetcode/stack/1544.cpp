class Solution {
public:
    string makeGood(string s) {
        vector<char> v;
        for (auto& i : s) {
            if (!v.empty()) {
                if (v.back() == i + 32 || v.back() == i - 32) {
                    v.pop_back();
                }
                else
                    v.push_back(i);
            }
            else
                v.push_back(i);
        }
        string w{""};
        for (auto& i : v)
            w += i;
        return w;
    }
};

// 执行用时：4 ms, 在所有 C++ 提交中击败了51.01%的用户
// 内存消耗：6 MB, 在所有 C++ 提交中击败了87.65%的用户