class dequeue {
public:

    deque<int> q;

    void push(int x) {
        while (!q.empty() && x > q.back()) {
            q.pop_back();
        }
        q.push_back(x);
    }

    void pop(int x) {
        if (x == q.front()) 
            q.pop_front();
    }

    int getMax() {
        return q.front();
    }
};

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        
        vector<int> res;
        dequeue q;

        for (int i = 0; i < nums.size(); i++) {
            if (i < k - 1) {
                q.push(nums[i]);
            }
            else {
                q.push(nums[i]);
                res.push_back(q.getMax());
                q.pop(nums[i - k + 1]);
            }
        }

        return res;
    }
};

// 执行用时： 232 ms , 在所有 C++ 提交中击败了 65.66% 的用户
// 内存消耗： 128.8 MB , 在所有 C++ 提交中击败了 42.71% 的用户
