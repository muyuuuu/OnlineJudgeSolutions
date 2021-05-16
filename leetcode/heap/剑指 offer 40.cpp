class Solution {
public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        priority_queue<int> q;
        for (auto& i : arr) {
            q.push(i);
            if (q.size() > k) {
                q.pop();
            }
        }
        vector<int> ans;
        while (!q.empty()) {
            ans.push_back(q.top());
            q.pop();
        }
        return ans;
    }
};

// 执行用时：56 ms, 在所有 C++ 提交中击败了8.78%的用户
// 内存消耗：19.3 MB, 在所有 C++ 提交中击败了21.73%的用户