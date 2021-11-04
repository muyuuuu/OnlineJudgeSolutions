#include <iostream>
#include <cctype>
#include <stack>

int calculate(std::string s) {
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
    }

    while (!stk.empty()) {
        res += stk.top();
        stk.pop();
    }
    return res;
}

int main() {
    int a = calculate("32 + 21 * 22 / 2");
    std::cout << a << std::endl;
    return 0;
}
