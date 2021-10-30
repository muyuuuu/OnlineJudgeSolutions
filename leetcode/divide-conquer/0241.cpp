class Solution {
public:
    vector<int> diffWaysToCompute(string expression) {
        vector<int> res;
        for (int i = 0; i < expression.size(); i++) {
            if (expression[i] == '+' || expression[i] == '-' || expression[i] == '*') {
                auto left = diffWaysToCompute(expression.substr(0, i));
                auto right = diffWaysToCompute(expression.substr(i+1));
                for (auto a : left) {
                    for (auto b : right) {
                        if (expression[i] == '+')
                            res.push_back(a + b);
                        if (expression[i] == '-')
                            res.push_back(a - b);
                        if (expression[i] == '*')
                            res.push_back(a * b);
                    }
                }
            }
        }
        if (res.size() == 0)
            return {stoi(expression)};
        return res;
    }
};

// 执行用时： 8 ms , 在所有 C++ 提交中击败了 31.26% 的用户
// 内存消耗： 11 MB , 在所有 C++ 提交中击败了 67.24% 的用户
