class Solution {
public:
    int singleNumber(vector<int>& nums) {
        map<int, int> m;
        int flag = 0, len = nums.size();
        for (int i = 0; i < len; i++){
            m[nums[i]] ++;
        }
        for (int i = 0; i < len; i++){
            if (m[nums[i]] == 1){
                flag = nums[i];
                break;
            }
        }
        return flag;
    }
};