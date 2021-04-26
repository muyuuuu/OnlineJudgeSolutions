class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        unordered_map<int, deque<int> > m;
        int s = nums.size();
        bool flag{false};
        vector<int> res;

        for (int i = 0; i < s; i++) {
            flag = false;
            for (int j = i + 1; j < s; j++) {
                if (nums[j] > nums[i]) {
                    flag = true;
                    m[nums[i]].push_back(nums[j]);
                    break;
                }
            }
            
            if (flag == false) {
                for (int j = 0; j < i; j++) {
                    if (nums[j] > nums[i]) {
                        flag = true;
                        m[nums[i]].push_back(nums[j]);
                        break;
                    }
                }
            }

            if (flag == false)
                 m[nums[i]].push_back(-1);
        }

        for (auto& i : nums) {
            res.push_back(m[i].front());
            m[i].pop_front();
        }
        return res;
    }
};

// 执行用时：432 ms, 在所有 C++ 提交中击败了12.88%的用户
// 内存消耗：90.7 MB, 在所有 C++ 提交中击败了5.03%的用户