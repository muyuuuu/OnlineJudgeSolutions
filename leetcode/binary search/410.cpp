class Solution {
public:

    int build (int mid, int m, vector<int>& nums) {
        int t{0};
        for (int i = 0; i < nums.size(); ) {
            int cap = mid;
            while (i < nums.size()) {
                if (cap < nums[i])
                    break;
                cap -= nums[i];
                i++;
            }
            t++;
        }

        if (t <= m)
            return 1;

        return 0;
    }

    int splitArray(vector<int>& nums, int m) {

        int l{-2}, r{0}, res{INT_MAX};

        for (const auto& i : nums) {
            if (i > l)
                l = i;
            r += i;
        }

        while (l <= r) {
            int mid = l + (r - l) / 2;

            int a = build(mid, m, nums);

            if (a == 1) {
                if (mid < res)
                    res = mid;
                r = mid - 1;
            }
            else if (a == 0)
                l = mid + 1;
        }

        return res;
    }
};

// 执行用时： 4 ms , 在所有 C++ 提交中击败了 62.87% 的用户
// 内存消耗： 6.8 MB , 在所有 C++ 提交中击败了 96.78% 的用户
