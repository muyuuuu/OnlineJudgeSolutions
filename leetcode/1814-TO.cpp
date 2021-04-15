class Solution {
public:
    int countNicePairs(vector<int>& nums) {
        vector<int> rev;
        string s;
        int res{0};
        for (auto& i : nums){
            s = to_string(i);
            reverse(s.begin(), s.end());
            rev.push_back(stoi(s));
        }
        for (int i = 0; i < nums.size(); i++){
            for (int j = i + 1; j < nums.size(); j++){
                if (nums[i] + rev[j] == nums[j] + rev[i])
                    res++;
            }
        }
        return res;
    }
};