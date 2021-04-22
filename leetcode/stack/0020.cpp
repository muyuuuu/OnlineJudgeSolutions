class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        bool flag{false}, flag1{false};
        if (s.size() %2 != 0)
            return false;
        for (auto& i : s) {
            if (i == '(') {
                flag1 = true;
                st.push(i);
            }
            else if (i == '[') {
                st.push(i);
                flag1 = true;
            }
            else if (i == '{') {
                flag1 = true;
                st.push(i);
            }
            else if (i == ')') {
                if (st.size() >= 1) {
                    if ( st.top() == '(')
                        st.pop();
                    else
                        return false;
                }
                else
                    return false;
            } 
            else if (i == ']') {
                if (st.size() >= 1){
                    if (st.top() == '[')
                        st.pop();
                    else
                        return false;
                }
                else
                    return false;
            }
            else if (i == '}') {
                if (st.size() >= 1) {
                    if (st.top() == '{')
                        st.pop();
                    else
                        return false;
                }
                else
                    return false;
            } 
        }
        st.empty() && flag1 == true ? flag = true : flag = false;
        return flag;
    }
};

// 执行用时：0 ms, 在所有 C++ 提交中击败了100.00%的用户
// 内存消耗：6.2 MB, 在所有 C++ 提交中击败了57.37%的用户