class SeatManager {
private:
    priority_queue<int, vector<int>, greater<int> > q;
    int n;
public:
    SeatManager(int n) {
        for (int i = 1; i <= n; i++) {
            q.push(i);
        }
    }
    
    int reserve() {
        n = q.top();
        q.pop();
        return n;
    }
    
    void unreserve(int seatNumber) {
        q.push(seatNumber);
    }
};

/**
 * Your SeatManager object will be instantiated and called as such:
 * SeatManager* obj = new SeatManager(n);
 * int param_1 = obj->reserve();
 * obj->unreserve(seatNumber);
 */

// 执行用时：540 ms, 在所有 C++ 提交中击败了40.82%的用户
// 内存消耗：144.2 MB, 在所有 C++ 提交中击败了44.49%的用户