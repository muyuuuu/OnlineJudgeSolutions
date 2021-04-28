class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> res;
        stack<int> s;
        bool flag{false};

        for (auto& i : asteroids) {
            // 空，压栈
            if (s.empty())
                s.push(i);
            // 栈顶向左移动，压栈
            else if (s.top() < 0)
                s.push(i);
            // 栈顶向右
            else if (s.top() > 0) {
                // 当前向右，压栈
                if (i > 0)
                    s.push(i);
                // 当前向左，碰撞
                else {
                    i = abs(i);
                    // 如果向左的小，不动
                    if (i < s.top()) 
                        continue;
                    // 如果向左的大
                    else {
                        // 栈非空
                        while (!s.empty()) {
                            // 栈顶向右 碰撞
                            if (s.top() > 0) {
                                if (i > s.top())
                                    s.pop();
                                else if (i == s.top()) {
                                    s.pop();
                                    break;
                                }
                                else {
                                    break;
                                }
                            }
                            else if (s.top() < 0) {
                                s.push(-i);
                                break;
                            }
                            if (s.empty()){
                                s.push(-i);
                                break;
                            }
                        }
                    }
                }
            }
        }
        while (!s.empty()){
            res.push_back(s.top());
            s.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};

// 执行用时：20 ms, 在所有 C++ 提交中击败了34.58%的用户
// 内存消耗：17.5 MB, 在所有 C++ 提交中击败了11.23%的用户