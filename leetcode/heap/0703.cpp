class KthLargest {
public:
    priority_queue<int, vector<int>, greater<int>> q;
    int k;
    KthLargest(int k, vector<int>& nums) {
        this->k = k;
        for (auto& x: nums) {
            add(x);
        }
    }
    
    int add(int val) {
        q.push(val);
        if (q.size() > k) {
            q.pop();
        }
        return q.top();
    }
};

// 执行用时：40 ms, 在所有 C++ 提交中击败了61.92%的用户
// 内存消耗：19.3 MB, 在所有 C++ 提交中击败了77.55%的用户