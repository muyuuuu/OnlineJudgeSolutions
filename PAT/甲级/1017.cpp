#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

const int maxn = 10005;

struct person 
{
    int come, time;
} p[maxn];

int cmp(person p1, person p2) 
{
    return p1.come < p2.come; 
}

int n, k, cnt, total;

int main() {
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; i++) 
    {
        int hh, ss, mm, tt;
        scanf("%d:%d:%d %d", &hh, &mm, &ss, &tt);
        // 全部转化为秒
        int sum = hh * 3600 + mm * 60 + ss;
        // 超算 17 点不算 17 x 3600 = 61200
        if (sum > 61200) 
            continue;
        // 处理的时间化为秒
        p[++cnt].time = tt * 60;
        // 记录到来的时间
        p[cnt].come = sum;
    }
    // 按照来的时间排序
    sort(p + 1, p + 1 + cnt, cmp);
    // 优先级队列 先输出
    priority_queue<int, vector<int>, greater<int> > q;
    // k 个窗口 上午八点的时间 8 x 3600 = 28800
    for (int i = 1; i <= k; ++i) 
        q.push(28800);
    // cnt 个有效的人
    // 按到来的顺序压入人员 
    for (int i = 1; i <= cnt; ++i) 
    {
        // 如果到来的人比q中最先结束的人要晚，此时没有等待时间，直接压入即可
        if (q.top() <= p[i].come) 
        {
            q.push(p[i].come + p[i].time);
            q.pop();
        } 
        // 如果到来的人比最先结束的人早，说明要等待
        else 
        {
            // 等待时间为最快结束人员的时间减去来到的时间
            total += q.top() - p[i].come;
            // 且此人离去的时间为最快结束的人的时间加上这个人的处理时间
            q.push(q.top() + p[i].time);
            // 弹出离去的人
            q.pop();
        }
    }
    (!cnt) ? printf("0.0\n") : printf("%.1lf", ((double)total/60.0)/(double) cnt);
    return 0;
}