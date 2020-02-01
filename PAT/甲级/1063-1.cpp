#include<iostream>
#include<set>
#include<algorithm>
#include<vector>

using namespace std;

set<string> s;
set<string> common, diff;
vector<set<string>> v;

void print_query(int query1, int query2, int flag)
{
    //交集
    set_intersection(v[query1].begin(), v[query1].end(), v[query2].begin(), v[query2].end(), inserter(common, common.begin()));
    float a = 0;
    for (auto it = common.begin(); it != common.end(); it++)
    {
        a++;
    }
    // 差集
    float b = v[query2].size();
    set_difference(v[query1].begin(), v[query1].end(), common.begin(), common.end(), inserter(diff, diff.begin()));
    for (auto it = diff.begin(); it != diff.end(); it++)
    {
        b++;
    }
    diff.clear();
    common.clear();
    // cout << b << "  ";
    if (flag == 1)
    {
        printf("%.1f", a/b*100);
        cout << "%" ;
    }
    else
    {
        printf("%.1f", a/b*100);
        cout << "%" << endl;
    }
}

int main()
{
    int n;
    cin >> n;
    int temp;
    string str;
    for (int i = 0; i < n; i++)
    {
        cin >> temp;
        for (int j = 0; j < temp; j++)
        {
            cin >> str;
            s.insert(str);
        }    
        v.push_back(s);
        s.clear();
    }
    int k;
    cin >> k;
    int query1, query2;
    int flag = 0;
    for (int i = 0; i < k; i++)
    {
        cin >> query1 >> query2;
        if (i == k - 1)
        {
            flag = 1;
            print_query(query1-1, query2-1, flag);
        }
        else
        {
            print_query(query1-1, query2-1, flag);
        }
    }
    return 0;
}
