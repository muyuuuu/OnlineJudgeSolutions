class myqueue{
public:
    priority_queue<int> q1;
    priority_queue<int, vector<int>, greater<int>> q2;

    void push(int val) {
        if (q1.size() == q2.size()) {
            q1.push(val);
            auto a = q1.top();
            q1.pop();
            q2.push(a);
        } else {
            q2.push(val);
            auto a = q2.top();
            q2.pop();
            q1.push(a);
        }
    }

    double getMid() {
        if (q1.size() == q2.size())
            return (q1.top() + q2.top()) * 1.0 / 2;
        return q2.top(); 
    }
};

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        myqueue q;
        for (auto i : nums1)
            q.push(i);
        for (auto i : nums2)
            q.push(i);
        return q.getMid();
    }
};

// 执行用时： 52 ms , 在所有 C++ 提交中击败了 6.43% 的用户
//  内存消耗： 87.8 MB , 在所有 C++ 提交中击败了 5.10% 的用户