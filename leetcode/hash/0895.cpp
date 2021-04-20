class FreqStack {
public:
    int freq{0};
    unordered_map<int, int> m1;
    unordered_map<int, stack<int> >m2;
    
    FreqStack() {

    }
    
    void push(int val) {
        m1[val]++;
        freq = max(freq, m1[val]);
        m2[m1[val]].push(val);
    }
    
    int pop() {
        auto x = m2[freq].top();
        m2[freq].pop();
        m1[x]--;
        if (m2[freq].size() == 0)
            freq--;
        return x;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */

// 执行用时：224 ms, 在所有 C++ 提交中击败了58.74%的用户
// 内存消耗：84.5 MB, 在所有 C++ 提交中击败了32.86%的用户