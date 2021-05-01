class CustomStack {
private:
    deque<int> d;
    int s;
public:
    CustomStack(int maxSize) {
        s = maxSize;
    }
    
    void push(int x) {
        if (d.size() < s) {
            d.push_back(x);
        }
    }
    
    int pop() {
        int v;
        if (!d.empty()) {
            v = d.back();
            d.pop_back();
        }
        else
            v = -1;
        return v;
    }
    
    void increment(int k, int val) {
        if (k > d.size())
            k = d.size();
        for (int i = 0; i < k; i++) {
            d[i] += val;
        }
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */

// 执行用时：52 ms, 在所有 C++ 提交中击败了23.86%的用户
// 内存消耗：17.6 MB, 在所有 C++ 提交中击败了87.91%的用户