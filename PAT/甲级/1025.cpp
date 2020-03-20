#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct node
{
    string id;
    int score;
    int local_number;
    int local_rank;
    int final_rank; 
};

vector<node> v;

int cmp(node a, node b)
{
    return a.score != b.score ? a.score > b.score : a.id < b.id;
}

int main(int argc, char const *argv[])
{
    int n, k, score, key = 1, rank;
    string str;
    cin >> n;
    node temp;
    vector<node> local[n];
    for (int i = 0; i < n; i++)
    {
        cin >> k;
        for (int j = 0; j < k; j++)
        {
            cin >> str >> score;
            temp.id = str;
            temp.score = score;
            temp.local_number = key;
            v.push_back(temp);
            local[key - 1].push_back(temp);
        }
        sort(local[key - 1].begin(), local[key - 1].end(), cmp);
        for (int j = 0; j < local[key - 1].size(); j++)
        {
            if (j != 0 && local[key - 1][j].score != local[key - 1][j-1].score)
                rank = j + 1;
            if (j == 0)
                rank = 1;            
            local[key - 1][j].local_rank = rank;
        }
        for (int l = 0; l < local[key - 1].size(); l++)
        {
            for (int j = v.size() - k; j < v.size(); j++)
            {
                if (v[j].local_number == key && v[j].id == local[key - 1][l].id)
                {
                    v[j].local_rank = local[key - 1][l].local_rank;
                    continue;
                }
            }
        }
        key++;
    }
    cout << v.size() << endl;
    sort(v.begin(), v.end(), cmp);
    for (int i = 0; i < v.size(); i++)
    {
        if (i != 0 && v[i].score != v[i-1].score)
            rank = i + 1;
        if (i == 0)
            rank = 1;
        cout << v[i].id << " " << rank << " " << v[i].local_number << " " << v[i].local_rank << endl;
    }
    return 0;
}
