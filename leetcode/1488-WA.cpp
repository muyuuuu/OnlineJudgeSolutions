class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        unordered_map<int, int> m;
        int tmp1{0}, tmp2{0}, flag{0};
        vector<int> ans;
        stack<int> rain;
        for(auto& i : rains){
            if (i != 0){
                ans.push_back(-1);
                rain.push(i);
                m[i]++;
                if (m[i] >= 2){
                    ans.clear();
                    break;
                }
            }
            else{
                if (!rain.empty()){
                    m[rain.top()] --;
                    ans.push_back(rain.top());
                    rain.pop();
                }
                else {
                    ans.push_back(1);
                }
            }
        }
        return ans;
    }
};

// [1,2,0,2,3,0,1] 如何调节抽哪一个？