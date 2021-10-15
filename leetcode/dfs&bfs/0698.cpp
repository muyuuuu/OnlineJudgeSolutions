class Solution {
public:

    static bool cmp(int a, int b) {
        return a > b;
    }

    bool canPartitionKSubsets(vector<int>& nums, int k) {
        if(k > nums.size())
            return false;
        int sum{0};
        for (auto& i : nums)
            sum += i;
        if (sum % k != 0)
            return false;

        sort(nums.begin(), nums.end(), cmp);
        int target = sum / k;
        vector<int> bucket(k, 0);

        return dfs(nums, bucket, target, 0);
    }

    bool dfs(vector<int>& nums, vector<int>& bucket, int target, int idx) {
        if (idx == nums.size()) {
            for (auto& i : bucket)
                if (i != target)
                    return false;
            return true;
        }

        for (int i = 0; i < bucket.size(); i++) {
            if (bucket[i] + nums[idx] > target)
                continue;
            else {
                bucket[i] += nums[idx];
                if (dfs(nums, bucket, target, idx + 1))
                    return true;
                bucket[i] -= nums[idx];              
            }
        }

        return false;
    }
};

// 执行用时： 108 ms , 在所有 C++ 提交中击败了 17.79% 的用户
// 内存消耗： 8.7 MB , 在所有 C++ 提交中击败了 83.30% 的用户
