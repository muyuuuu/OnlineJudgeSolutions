class MyQueue {
private:
    deque<int> d;
public:
    /** Initialize your data structure here. */
    MyQueue() {

    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        d.push_back(x);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        auto a = d.front();
        d.pop_front();
        return a;
    }
    
    /** Get the front element. */
    int peek() {
        auto a = d.front();
        return a;
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return d.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */

// 执行用时：0 ms, 在所有 C++ 提交中击败了100.00%的用户
// 内存消耗：6.6 MB, 在所有 C++ 提交中击败了99.77%的用户