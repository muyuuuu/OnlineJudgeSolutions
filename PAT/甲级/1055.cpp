#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct node
{
    string name;
    int age;
    int worth;
};

vector<node> v;

int cmp(node a, node b)
{
    return a.worth != b.worth ? a.worth > b.worth : (a.age != b.age ? a.age < b.age : (a.name < b.name));
}

int main(int argc, char const *argv[])
{
    int n, k, a, w;
    string id;
    scanf("%d %d", &n, &k);
    node temp;
    for (int i = 0; i < n; i++)
    {
        cin >> id >> a >> w;
        temp.name = id;
        temp.age = a;
        temp.worth = w;
        v.push_back(temp);
    }
    int num, max, min, flag = 0;
    sort(v.begin(), v.end(), cmp);
    for (int i = 0; i < k; i++)
    {
        flag = 0;
        scanf("%d %d %d", &num, &min, &max);
        printf("Case #%d:\n", i + 1);
        for (int j = 0; j < v.size(); j++)
        {
            if (v[j].age >= min && v[j].age <= max)
            {
                flag += 1;
                cout << v[j].name;
                printf(" %d %d\n", v[j].age, v[j].worth);
            }
            if (flag == num) break;
        }   
        if (flag == 0) cout << "None" << endl;
    }
    return 0;
}
