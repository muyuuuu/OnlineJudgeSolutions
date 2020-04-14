#include <iostream>
#include <vector>

using namespace std;

struct node
{
    int data;
    int next;
}list[100000];

vector <int> ans[3];

int main(int argc, char const *argv[])
{
    int start, n, k, a;
    cin >> start >> n >> k;
    for (int i = 0; i < n; i++)
    {
        cin >> a;
        cin >> list[a].data >> list[a].next;
    }
    int p = start;
    while (p != -1)
    {
        if (list[p].data < 0)
            ans[0].push_back(p);
        else if (list[p].data >= 0 && list[p].data <= k)
            ans[1].push_back(p);
        else
            ans[2].push_back(p);
        p = list[p].next;
    }
    int flag = 0;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < ans[i].size(); j++) 
        {
            if (flag == 0) 
            {
                printf("%05d %d ", ans[i][j], list[ans[i][j]].data);
                flag = 1;
            } else 
            {
                printf("%05d\n%05d %d ", ans[i][j], ans[i][j], list[ans[i][j]].data);
            }
        }
    }
    printf("-1");
    return 0;
}
