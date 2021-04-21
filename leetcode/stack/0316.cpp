class Solution {
public:
    string removeDuplicateLetters(string s) {
        string w{""};
        stack<char> st;
        vector<int> count(26, 0);
        vector<bool> isin(26, false);
        
        for (auto& i : s) {
            count[i - 'a'] ++;
        }
        
        for (auto& i : s) {
            count[i - 'a'] --;
            if (isin[i - 'a'] == false) {
                while (!st.empty() && st.top() > i) {
                    if (count[st.top() - 'a'] <= 0)
                        break;
                    isin[st.top() - 'a'] = false;
                    st.pop();
                }
                st.push(i);
                isin[i - 'a'] = true;
            }
        }
        
        while (!st.empty()) {
            w += st.top();
            st.pop();
        }
        
        reverse(w.begin(), w.end());
        return w;
    }
};

// 执行用时：4 ms, 在所有 C++ 提交中击败了64.09%的用户
// 内存消耗：6.7 MB, 在所有 C++ 提交中击败了23.06%的用户