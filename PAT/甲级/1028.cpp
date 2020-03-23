#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct node
{
    string id;
    string name;
    int grade;
};

vector <node> v;

int cmp1(node a, node b)
{
    return a.id < b.id;
}

int cmp2(node a, node b)
{
    return a.name != b.name ? a.name < b.name : a.id < b.id;
}

int cmp3(node a, node b)
{
    return a.grade != b.grade ? a.grade < b.grade : a.id < b.id;
}

int main(int argc, char const *argv[])
{
    int n, c, grade;
    cin >> n >> c;
    node temp;
    string id, name;
    for (int i = 0; i < n; i++)
    {
        cin >> id >> name >> grade;
        temp.id = id;
        temp.name = name;
        temp.grade = grade;
        v.push_back(temp);
    }
    if (c == 1)
    {
        sort(v.begin(), v.end(), cmp1);
        for (int i = 0; i < n; i++)
            cout << v[i].id << " " << v[i].name << " " << v[i].grade << endl;
        return 0;
    }
    if (c == 2)
    {
        sort(v.begin(), v.end(), cmp2);
        for (int i = 0; i < n; i++)
            cout << v[i].id << " " << v[i].name << " " << v[i].grade << endl;
        return 0;
    }
    if (c == 3)
    {
        sort(v.begin(), v.end(), cmp3);
        for (int i = 0; i < n; i++)
            cout << v[i].id << " " << v[i].name << " " << v[i].grade << endl;
        return 0;
    }
    return 0;
}
