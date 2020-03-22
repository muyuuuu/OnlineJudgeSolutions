#include <iostream>
const int maxn = 200005;
int n, m, a1[maxn], a2[maxn], cnt = 0, i, j, ans;
int main() {
    scanf("%d", &n);
    for(i = 0; i < n; i++) 
        scanf("%d", &a1[i]);
    scanf("%d", &m);
    for(i = 0; i < m; i++) 
        scanf("%d", &a2[i]);
    // 放到第二个数列 最后在减去多余的 1 
    // 0 1 2 3
    // 5 6 7 8 9
    int target = (n + m + 1) / 2;
    i = 0, j = 0;
    while(i < n && j < m) {
        ans = a1[i] <= a2[j] ? a1[i++] : a2[j++];
        if(++cnt == target) 
            break;
    }
    if(i < n && cnt < target)  
        ans = a1[i + target - cnt - 1];
    else if(j < m && cnt < target) 
        ans = a2[j + target - cnt - 1];
    printf("%d", ans);
    return 0;
}