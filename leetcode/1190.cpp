class Solution {
public:
    string reverseParentheses(string s) {
        stack<string> st;
        string w;
        for (auto& i : s) {
            if (i == '(') {
                st.push(w);
                w = "";
            } 
            else if (i == ')') {
                reverse(w.begin(), w.end());
                w = st.top() + w;
                st.pop();
            }
            else {
                w += i;
            }
        }
        return w;
    }
};

// 执行用时：0 ms, 在所有 C++ 提交中击败了100.00%的用户
// 内存消耗：6.5 MB, 在所有 C++ 提交中击败了41.16%的用户