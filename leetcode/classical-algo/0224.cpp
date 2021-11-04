#include <iostream>
#include <cctype>
#include <stack>

int subcal(std::string s, int& idx) {
    int res{0};
    std::stack<int> stk;
    int num{0};
    // 第一个数字添加符号
    char sign{'+'};
    int tmp;
    
    for (int i = 0; i < s.size(); i++) {
        char c = s[i];
        if (std::isdigit(c))
            num = 10 * num + (c - '0');
        if (c == '(') {
            num = subcal(s.substr(i + 1), idx);
            i += idx + 2;
            if (i >= s.size())
                i = s.size() - 1;
            c = s[i];
        }
        // 处理空格
        if (!std::isdigit(c) && c != ' ' || i == s.size() - 1) {
            switch (sign) {
                case '+':
                    stk.push(num); break;
                case '-':
                    stk.push(-num); break;
                case '*':
                    tmp = stk.top();
                    stk.pop();
                    stk.push(tmp * num);
                    break;
                case '/':
                    tmp = stk.top();
                    stk.pop();
                    stk.push(tmp / num);
                    break;
            }
            sign = c;
            num = 0;
        }
        if (c == ')') {
            idx = i;
            break;
        }
    }

    while (!stk.empty()) {
        res += stk.top();
        stk.pop();
    }
    return res;
}

int calculate(std::string s) {
    int idx;
    return subcal(s, idx);
}

int main() {
    int a = calculate("(1+(4+5+2)-3)+(6+8)");
    std::cout << a << std::endl;
    return 0;
}
