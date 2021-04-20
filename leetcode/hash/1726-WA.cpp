class Solution {
public:
    vector<string> computeSimilarities(vector<vector<int>>& docs) {
        int d{0};
        double res;
        vector<string> ans;
        char tmp[256];
        for (int i = 0; i < docs.size(); i++){
            unordered_map<int, int> m;
            for (auto& k : docs[i]){
                m[k] = 1;
            }
            for (int j = i + 1; j < docs.size(); j++){
                d = 0;
                for (auto& k : docs[j]){
                    if (m[k] == 1){
                        d++;
                    }
                }
                if (d > 0) {
                    res = (d * 1.0 / (docs[i].size() + docs[j].size() - d));
                    sprintf(tmp, "%d,%d: %0.4lf", i, j, res);
                    ans.push_back(tmp);
                }
            }
        }
        return ans;
    }
};