#include <iostream>
#include <vector>

using namespace std;

int book[201], a[10001], dp[10001];

int main() 
{
    int n, m, x, l, num = 0, maxn = 0;
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= m; i++) 
    {
        scanf("%d", &x);
        book[x] = i;
    }
    scanf("%d", &l);
    // a 里面存储的是可使用颜色的顺序 
    // 取从小到大的排列就是答案
    for(int i = 0; i < l; i++) 
    {
        scanf("%d", &x);
        if(book[x] >= 1)
            a[num++] = book[x];
    }
    // 动态规划 
    // 解的数量要么是当前的 dp 数组值
    // 要么是上一个 dp 数组值 + 1
    for(int i = 0; i < num; i++) 
    {
        dp[i] = 1;
        for(int j = 0; j < i; j++)
            if(a[i] >= a[j])
                dp[i] = max(dp[i], dp[j] + 1);
        maxn = max(dp[i], maxn);
    }
    printf("%d", maxn);
    return 0;
}
