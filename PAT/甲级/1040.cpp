#include <iostream>
using namespace std;
int dp[1010][1010];
int main() {
    string s;
    getline(cin, s);
    int len = s.length(), ans = 1;
    // 初始化长度为2的序列
    for(int i = 0; i < len; i++) {
        dp[i][i] = 1;
        if(i < len - 1 && s[i] == s[i+1]) {
            dp[i][i+1] = 1;
            ans = 2;
        }
    }
    // i->j的差距为3,4,5逐渐递增，先算小的，保证计算大的时候，小的已经更新
    // 即计算d[i][j] 时候，d[i+1][j-1]需要已经更新
    for(int L = 3; L <= len; L++) {
        for(int i = 0; i + L - 1 < len; i++) {
            int j = i + L -1;
            if(s[i] == s[j] && dp[i+1][j-1] == 1) {
                dp[i][j] = 1;
                ans = L;
            }
        }
    }
    printf("%d", ans);
    return 0;
}