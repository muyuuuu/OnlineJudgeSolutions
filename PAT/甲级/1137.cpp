#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

struct node
{
    string id;
    int online;
    int mid;
    int final;
    int result;
};

vector<node> v, ans;
map<string, int> idx;

int cmp(node a, node b)
{
    return a.result != b.result ? a.result > b.result : a.id < b.id;
}

int main(int argc, char const *argv[])
{
    int p, m, n, score, cnt = 1;
    string s;
    cin >> p >> m >> n;
    for (int i = 0; i < p; i++)
    {
        cin >> s >> score;
        if (score >= 200)
        {
            v.push_back(node{s, score, -1, -1, 0});
            idx[s] = cnt++;
        }
    }
    for (int i = 0; i < m; i++)
    {
        cin >> s >> score;
        if (idx[s] != 0) 
            v[idx[s] - 1].mid = score;
    }
    for (int i = 0; i < n; i++)
    {
        cin >> s >> score;
        int temp = idx[s] - 1;
        if (idx[s] != 0)
        {
            v[temp].final = v[temp].result = score;
            if (v[temp].mid > score)
                v[temp].result = int(0.4 * v[temp].mid + 0.6 * v[temp].final + 0.5);
        }
    }
    for (int i = 0; i < v.size(); i++)
        if (v[i].result >= 60) 
            ans.push_back(v[i]);
    sort(ans.begin(), ans.end(), cmp);
    for (int i = 0; i < ans.size(); i++)
        printf("%s %d %d %d %d\n", ans[i].id.c_str(), ans[i].online, ans[i].mid, ans[i].final, ans[i].result);
    return 0;
}
