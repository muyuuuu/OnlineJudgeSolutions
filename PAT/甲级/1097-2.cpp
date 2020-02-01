#include<iostream>

using namespace std;

struct NODE{
    int add, key, next;
    bool flag;
}node[100005], node1[100005], node2[100005], node3[100005];

int main()
{
    int add, num;
    int a, k, n;
    cin >> add >> num;
    for (int i = 0; i < num; i++)
    {
        scanf("%d%d%d", &a, &k, &n);
        node[a] = {a, k, n, false};
    }
    // cout << " here1 " << endl;
    int cnt=0, cnt1=0, cnt2=0;
    // 全部链表被访问记录
    for (int i = add; i != -1; i = node[i].next)
    {
        node[i].flag = true;
        node3[cnt] = node[i];
        cnt++;
    }
    int temp = 0;
    for (int i = 0; i < cnt; i++)
    {
        temp = node3[i].key;
        for (int j = i + 1 ; j < cnt; j ++)
        {
            if ( ((node3[j].key == temp ) || (node3[j].key == -temp && temp <= 0)) && (node3[j].flag == true))
            {
                node3[j].flag = false;
                node2[cnt2] = node3[j];
                cnt2++;
            }
        }
        if (node3[i].flag == true)
        {
            node1[cnt1] = node3[i];
            cnt1++;
        }
    }
    // cout << endl;
    for (int i = 0; i < cnt1; i++)
    {
        printf("%05d %d ", node1[i].add, node1[i].key);
        if (i == cnt1 - 1)
            printf("-1\n");
        else
            printf("%05d\n", node1[i+1].add);
    }
    // cout << endl;
    for (int i = 0; i < cnt2; i++)
    {
        printf("%05d %d ", node2[i].add, node2[i].key);
        if (i == cnt2 - 1)
            printf("-1");
        else
            printf("%05d\n", node2[i+1].add);
    }
    return 0;
}