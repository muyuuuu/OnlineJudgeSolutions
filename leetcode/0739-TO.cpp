class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        vector<int> res;
        int flag = 0;
        for (int i = 0; i < T.size(); i++) {
            for (int j = i + 1; j < T.size(); j++) {
                if (T[j] > T[i]){
                    flag = 1;
                    res.push_back(j - i);
                    break;
                }
            }
            if (flag == 0) {
                res.push_back(0);
            }
            flag = 0;
        }
        return res;
    }
};