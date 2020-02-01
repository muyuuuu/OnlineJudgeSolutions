#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> post, in;

struct node
{
    int index, value;
};

vector<node> ans;

bool cmp(node a, node b)
{
    return a.index < b.index;
}


void pre(int root, int start, int end, int index)
{
    if (start > end)
        return;
    int i = start;
    while(i < end && in[i] != post[root])
        i++;
    // printf("%d ", post[root]);
    ans.push_back({index, post[root]});
    pre(root - 1 + i - end, start, i - 1, 2 * index + 1);
    pre(root - 1, i + 1, end, 2 * index + 2);
}

int main()
{
    int num;
    cin >> num;
    int temp;
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < num; j++)
        {
            cin >> temp;
            if (i == 0)
            {
                post.push_back(temp);
            }
            if (i == 1)
            {
                in.push_back(temp);
            }
        }
    }
    pre(num - 1, 0, num - 1, 0);
    sort(ans.begin(), ans.end(), cmp);
    for (int i = 0; i < ans.size(); i++)
    {
        if (i != ans.size() - 1)
            cout << ans[i].value << " " ;
        else
            cout << ans[i].value;
    }
    return 0;
}