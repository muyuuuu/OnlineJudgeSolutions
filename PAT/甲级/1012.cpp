#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct node
{
    string id;
    int c;
    int m;
    int e;
    float a;
    int rank_a;
    int rank_c;
    int rank_m;
    int rank_e;
};

vector<node> v;

int cmpa(node a, node b)
{
    return a.a > b.a;
}

int cmpc(node a, node b)
{
    return a.c > b.c;
}

int cmpm(node a, node b)
{
    return a.m > b.m;
}

int cmpe(node a, node b)
{
    return a.e > b.e;
}

int main(int argc, char const *argv[])
{
    int n, m, c, e, math, rank = 1, flag = -1;
    float a;
    cin >> n >> m;
    node temp;
    string str;
    for (int i = 0; i < n; i ++)
    {
        cin >> str >> c >> math >> e;
        temp.id = str;
        temp.c = c;
        temp.m = math;
        temp.e = e;
        temp.a = (c + math + e) / 3;
        v.push_back(temp);
    }
    sort(v.begin(), v.end(), cmpa);
    for (int i = 0; i < v.size(); i++)
    {
        if (i != 0 && v[i].a != v[i - 1].a)
            rank = i + 1;
        if (i == 0)
            rank = 1;
        v[i].rank_a = rank;
    }
    sort(v.begin(), v.end(), cmpc);
    for (int i = 0; i < v.size(); i++)
    {
        if (i != 0 && v[i].c != v[i - 1].c)
            rank = i + 1;
        if (i == 0)
            rank = 1;
        v[i].rank_c = rank;
    }
    sort(v.begin(), v.end(), cmpm);
    for (int i = 0; i < v.size(); i++)
    {
        if (i != 0 && v[i].m != v[i - 1].m)
            rank = i + 1;
        if (i == 0)
            rank = 1;
        v[i].rank_m = rank;
    }
    sort(v.begin(), v.end(), cmpe);
    for (int i = 0; i < v.size(); i++)
    {
        if (i != 0 && v[i].e != v[i - 1].e)
            rank = i + 1;
        if (i == 0)
            rank = 1;
        v[i].rank_e = rank;
    }
    for (int i = 0; i < m; i++)
    {
        flag = -1;
        cin >> str;
        for (int j = 0; j < v.size(); j++)
        {
            if (v[j].id == str)
            {
                flag = j;
                break;
            }
        }
        if (flag == -1)
        {
            cout << "N/A" << endl;
        }
        else
        {
            if (v[flag].rank_a <= v[flag].rank_c && v[flag].rank_a <= v[flag].rank_m && v[flag].rank_a <= v[flag].rank_e) 
                cout << v[flag].rank_a << " A" << endl;
            else if (v[flag].rank_c <= v[flag].rank_m && v[flag].rank_c <= v[flag].rank_e) 
                cout << v[flag].rank_c << " C" << endl;
            else if (v[flag].rank_m <= v[flag].rank_e) 
                cout << v[flag].rank_m << " M" << endl;
            else  
                cout << v[flag].rank_e << " E" << endl;
        }
    }
    return 0;
}
