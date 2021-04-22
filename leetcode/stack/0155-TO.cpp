class MinStack {
private:
    vector<int> st;
public:
    /** initialize your data structure here. */
    MinStack() {

    }
    
    void push(int val) {
        st.push_back(val);
    }
    
    void pop() {
        if (st.size() >= 1)
            st.pop_back();
    }
    
    int top() {
        return st.back();
    }
    
    int getMin() {
        auto res = min_element(begin(st), end(st));
        return *res;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */

// 执行用时：164 ms, 在所有 C++ 提交中击败了5.01%的用户
// 内存消耗：15.9 MB, 在所有 C++ 提交中击败了31.98%的用户