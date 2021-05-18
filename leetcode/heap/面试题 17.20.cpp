class MedianFinder {
private:
    priority_queue<int, vector<int>, greater<int> > maxq;
    priority_queue<int, vector<int>, less<int> > minq;
    int n;
public:
    /** initialize your data structure here. */
    MedianFinder() {

    }
    
    void addNum(int num) {
        if (maxq.size() == minq.size()) {
            maxq.push(num);
            n = maxq.top();
            maxq.pop();
            minq.push(n);
        }
        else {
            minq.push(num);
            n = minq.top();
            minq.pop();
            maxq.push(n);
        }
    }
    
    double findMedian() {
        if (maxq.size() == minq.size()) {
            return (maxq.top() * 1.0 + minq.top()) / 2;
        }
        return minq.top() * 1.0;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */

// 执行用时：136 ms, 在所有 C++ 提交中击败了41.31%的用户
// 内存消耗：40.7 MB, 在所有 C++ 提交中击败了70.27%的用户