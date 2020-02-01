#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

struct node {
    double data;
    vector<int> child;
};
vector<node> v;

// float 过不去
double ans=0, r, p;

void dfs(int index, int depth)
{
    if (v[index].child.size() == 0)
    {
        ans += v[index].data * pow((1 + r), depth);
        return;
    }
    else
    {
        for (int i = 0; i < v[index].child.size(); i++)
        {
            dfs(v[index].child[i], depth+1);
        }
    }
}

int main()
{
    int num;
    cin >> num >> p >> r;
    int temp1; 
    int temp;
    double data;
    r = r / 100;
    v.resize(num);
    for (int i = 0; i < num; i++)
    {
        cin >> temp;
        if (temp == 0)
        {
            cin >> data;
            v[i].data = data;
        }
        else
        {
            for (int j = 0; j < temp; j++)
            {
                scanf("%d", &temp1);
                v[i].child.push_back(temp1);
            }
        }
    }
    int price;
    dfs(0, 0);
    printf("%.1f", ans*p);
    return 0;
}