class MedianFinder {
private:
    priority_queue<int, vector<int>, less<int> > maxq;
    priority_queue<int, vector<int>, greater<int> > minq;
public:
    /** initialize your data structure here. */
    MedianFinder() {

    }
    
    void addNum(int num) {
        if (minq.size() == maxq.size()) {
            minq.push(num);
            maxq.push(minq.top());
            minq.pop();
        }
        else {
            maxq.push(num);
            minq.push(maxq.top());
            maxq.pop();
        }
    }
    
    double findMedian() {
        if (minq.size() == maxq.size()) {
            return (minq.top() * 1.0 + maxq.top() * 1.0) / 2;
        }
        return maxq.top() * 1.0;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */

// 执行用时：132 ms, 在所有 C++ 提交中击败了46.56%的用户
// 内存消耗：40.7 MB, 在所有 C++ 提交中击败了66.00%的用户