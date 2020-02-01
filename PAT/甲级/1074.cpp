#include<iostream>
#include<algorithm>

using namespace std;

struct NODE
{
    int add, key, next;
    bool flag;
} node[100005], node1[100005];

int main()
{
    int add, line, re;
    cin >> add >> line >> re;
    int a, k, n;
    for(int i = 0; i < line; i++)
    {
        scanf("%d%d%d", &a, &k, &n);
        node[a] = {a, k, n, false};
    }
    int cnt = 0;
    for(int i = add; i != -1; i = node[i].next) {
        node[i].flag = true;
        node1[cnt] = node[i];
        cnt++;
    }
    for (int i = 0; i < cnt; i += re)
    {
        if (i + re > cnt)
        {
            break;
        }
        reverse(node1 + i, node1 + i + re);
    }
    
    for (int i = 0; i < cnt; i++)
    {
        printf("%05d %d ", node1[i].add, node1[i].key);
        
        if (i == cnt - 1)
        {
            printf("-1");
        }
        else
        {
            printf("%05d\n", node1[i+1].add);
        }
        // cout << node1[i].add << " " << node1[i].key <<endl;
    }
    return 0;
}