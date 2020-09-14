class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector <int> v;
        map<int, int> a;
        for (int i = 1; i <= nums.size(); i++){
            a[nums[i-1]] = i;
        }
        for (int i = 0; i < nums.size(); i++){
            int c = target - nums[i];
            if ((a[c] != 0) && i != a[c] - 1){
                v.push_back(i);
                v.push_back(a[c]-1);
                break;
            }
        }
        return v;
    }
};