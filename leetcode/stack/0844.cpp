class Solution {
public:
    
    string process(string& s){
        stack<char> stk;
        for (auto& i : s) {
            if (i == '#') {
                if (stk.empty())
                    continue;
                else 
                    stk.pop();
            }
            else
                stk.push(i);
        }
        string w{""};
        while (!stk.empty()) {
            w += stk.top();
            stk.pop();
        }
        return w;
    }
    
    bool backspaceCompare(string s, string t) {
        string t1 = process(s);
        string t2 = process(t);
        bool flag{false};
        if (t1 == t2)
            flag = true;
        return flag;
    }
};

// 执行用时：0 ms, 在所有 C++ 提交中击败了100.00%的用户
// 内存消耗：6.4 MB, 在所有 C++ 提交中击败了14.89%的用户