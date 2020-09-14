class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size(), len = 1, maxn = 1;
        if (n == 0) return 0;
        map<char, int> m;
        for (int i = 0; i < n; i++){
            m[s[i]]= 1;
            for (int j = i + 1; j < n; j++){
                if (m[s[j]] == 0){
                    m[s[j]] = 1;
                    len++;
                    if (len > maxn)
                        maxn = len;
                }
                else{
                    len = 1;
                    m.clear();
                    break;
                }
            }
        }
        return maxn;
    }
};