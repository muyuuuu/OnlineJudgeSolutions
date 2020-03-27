#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct node
{
    string name;
    string id;
    int grade;
};

vector <node> v;

int cmp(node a, node b)
{
    return a.grade > b.grade;
}

int main(int argc, char const *argv[])
{
    int n, flag = 0;
    cin >> n;
    node temp;
    for (int i = 0; i < n; i++)
    {
        cin >> temp.name >> temp.id >> temp.grade;
        v.push_back(temp);
    }
    sort(v.begin(), v.end(), cmp);
    int minn, maxn;
    cin >> minn >> maxn;
    for (int i = 0; i < v.size(); i++)
    {
        while (v[i].grade >= minn && v[i].grade <= maxn)
        {
            flag = 1;
            cout << v[i].name << " " << v[i].id << endl;
            i++;
        }
    }
    if (flag == 0) cout << "NONE";
    return 0;
}
