class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        int n = nums.size();
        int a = n * (n - 1) / 2;
        int b = a - k + 1;
        int v;
        priority_queue<int, vector<int>, greater<int> > q;
        
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                v = abs(nums[i] - nums[j]);
                q.push(v);
                if (q.size() > b)
                    q.pop();
            }
        }
        return q.top();
    }
};

// 超时，但看不懂其它答案