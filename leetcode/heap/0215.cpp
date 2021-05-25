class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> q;
        int n = nums.size() - k + 1;
        for (auto& i : nums) {
            q.push(i);
            if (q.size() > n)
                q.pop();
        }
        return q.top();
    }
};

// 执行用时：4 ms, 在所有 C++ 提交中击败了98.73%的用户
// 内存消耗：9.9 MB, 在所有 C++ 提交中击败了16.45%的用户