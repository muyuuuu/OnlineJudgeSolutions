class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int res{0};
        vector<int> presum(nums.size() + 1, 0);
        for (int i = 0; i < nums.size(); i++) {
            presum[i + 1] = (presum[i] + nums[i]);
        }
        for (int i = 1; i < presum.size(); i++) {
            for (int j = 0; j < i; j++) {
                if (presum[i] - presum[j] == k)
                    res++;
            }
        }
        return res;
    }
};
