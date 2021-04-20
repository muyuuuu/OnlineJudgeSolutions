class Solution {
public:
    int calculate(string s) {
        int res{0}, n = s.size();
        string w{""};
        stack<int> val;
        char op = '+';
        
        for (int i = 0; i < n; i++) {
            if (s[i] == ' ')
                continue;
            else if (!isdigit(s[i]))
                op = s[i];
            else {
                while (isdigit(s[i])) {
                    w += i;
                    i++;
                }
                res = stoi(w);
                if (op == '+')
                    val.push(res);
                else if (op == '-')
                    val.push(-res);
                else if (op == '*')
                    val.top() *= res;
                else
                    val.top() /= res;
                i--;
                w = "";
            }
        }
        res = 0;
        while (!val.empty()){
            res += val.top();
            val.pop();
        }
        return res;
    }
};

// 执行用时：12 ms, 在所有 C++ 提交中击败了56.98%的用户
// 内存消耗：8.4 MB, 在所有 C++ 提交中击败了73.64%的用户