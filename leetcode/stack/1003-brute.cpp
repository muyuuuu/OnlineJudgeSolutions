class Solution {
public:
    bool isValid(string s) {
        bool flag = false;
        while (s.size() > 0 && s.find("abc") != string::npos) {
            int pos = s.find("abc");
            s = s.erase(pos, 3);
            // return s;
        }
        if (s.size() == 0)
            flag = true;
        return flag;
    }
};

// 执行用时：768 ms, 在所有 C++ 提交中击败了5.20%的用户
// 内存消耗：7.9 MB, 在所有 C++ 提交中击败了91.27%的用户