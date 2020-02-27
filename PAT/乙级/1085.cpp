#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

struct node
{
    string id;
    float score;
};

struct node1
{
    string id;
    int score;
    int num;
};

map<string, vector<node>> m;

int cmp(node1 a, node1 b)
{
    return a.score != b.score ? a.score > b.score : a.num != b.num ? a.num < b.num : a.id < b.id;
}

int main(int argc, char const *argv[])
{
    int n;
    node temp;
    string school;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> temp.id >> temp.score;
        cin >> school;
        transform(school.begin(), school.end(), school.begin(), ::tolower);
        m[school].push_back(temp);
    }
    cout << m.size() << endl;
    vector<node1> v;
    float sum = 0;
    node1 temp1;
    for (auto it = m.begin(); it != m.end(); it++)
    {
        for (int j = 0; j < m[it->first].size(); j++)
        {
            if (m[it->first][j].id[0] == 'B') sum += m[it->first][j].score / 1.5;
            if (m[it->first][j].id[0] == 'A') sum += m[it->first][j].score;
            if (m[it->first][j].id[0] == 'T') sum += m[it->first][j].score * 1.5;
        }
        temp1.num = m[it->first].size();
        temp1.score = (int)sum;
        temp1.id = it->first;
        v.push_back(temp1);
        sum = 0;
    }
    sort(v.begin(), v.end(), cmp);
    int key = 1;
    for (int i = 0; i < m.size(); i++)
    {
        if (i != 0 && v[i - 1].score != v[i].score)
            key = i + 1;
        cout << key << " " << v[i].id << " " << v[i].score << " " << v[i].num << endl;
    }
    return 0;
}
