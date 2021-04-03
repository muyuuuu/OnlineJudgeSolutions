class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        map<string, int> m;
        vector <string> ans;
        int n = s.size() - 10;
        if (s.size() > 10){
            for (int i = 0; i <= n; i++){
                if (m[s.substr(i, 10)] == 0)
                    m[s.substr(i, 10)] = 1;
                else if (m[s.substr(i, 10)] == 1){
                    m[s.substr(i, 10)] = 2;
                    ans.push_back(s.substr(i, 10));
                }
            } 
        }
        return ans;
    }
};