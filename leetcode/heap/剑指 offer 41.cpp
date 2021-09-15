class MedianFinder {
private:
    priority_queue<int> maxq;
    priority_queue<int, vector<int>, greater<int>> minq;
public:
    /** initialize your data structure here. */
    MedianFinder() {

    }
    
    void addNum(int num) {
        if (maxq.size() == minq.size()){
            maxq.push(num);
            minq.push(maxq.top());
            maxq.pop();
        }
        else {
            minq.push(num);
            maxq.push(minq.top());
            minq.pop();
        }
    }
    
    double findMedian() {
        if ( maxq.size() == minq.size())
            return 1.0 * (minq.top() + maxq.top()) / 2;
        return minq.top() * 1.0;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
