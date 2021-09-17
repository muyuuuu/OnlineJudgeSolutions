class MyQueue {
public:        
    
    stack<int> s1;
    stack<int> s2;
    
    /** Initialize your data structure here. */
    MyQueue() {

    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        s1.push(x);
    }
    
    void move() {
        if (s2.empty()) {
            while (!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }
    }

    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        move();
        int a = s2.top();
        s2.pop();
        return a;
    }
    
    /** Get the front element. */
    int peek() {
        move();
        return s2.top();
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return s1.empty() && s2.empty();
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

// 执行用时： 0 ms , 在所有 C++ 提交中击败了 100.00% 的用户
// 内存消耗： 6.7 MB , 在所有 C++ 提交中击败了 96.33% 的用户
