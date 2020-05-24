#include <iostream>
#include <vector>

using namespace std;

int book[201], a[10001], dp[10001];

int main() 
{
    int n, m, x, l, num = 0, maxn = 0, count = 1;
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= m; i++) 
    {
        scanf("%d", &x);
        book[x] = i;
    }
    scanf("%d", &l);
    for(int i = 0; i < l; i++) 
    {
        scanf("%d", &x);
        if(book[x] >= 1)
            a[num++] = book[x];
    }
    for(int i = 0; i < num; i++) 
    {
        if (i == 0) maxn = a[i];
        else
        {
            if (a[i] >= maxn)
            {
                maxn = a[i];
                count++;
            }
        }
    }
    printf("%d", count);
    return 0;
}
