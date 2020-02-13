#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct node
{
    string id;
    int morality;
    int talent;
    int sum;
};

vector<node> v1, v2, v3, v4;

bool cmp(const node &a, const node &b)
{
    return a.sum != b.sum? a.sum > b.sum : (a.morality != b.morality? a.morality > b.morality: (a.id < b.id));
}

int main(int argc, char const *argv[])
{
    int m, l, h;
    cin >> m >> l >> h;
    string str;
    int a, b , k1 = 0, k2 = 0, k3 = 0, k4 = 0;
    v1.resize(100004);
    v2.resize(100004);
    v3.resize(100004);
    v4.resize(100004);
    for (int i = 0; i < m; i++)
    {
        cin >> str >> a >> b;
        if (a >= h && b >= h)
        {
            v1[k1].id = str;
            v1[k1].morality = a;
            v1[k1].talent = b;
            v1[k1].sum = a + b;
            k1++;
        } 
        else if (a >= h && b >= l)
        {
            v2[k2].id = str;
            v2[k2].morality = a;
            v2[k2].talent = b;
            v2[k2].sum = a + b;
            k2++;
        }
        else if(a >= l && b >= l && a >= b)
        {
            v3[k3].id = str;
            v3[k3].morality = a;
            v3[k3].talent = b;
            v3[k3].sum = a + b;
            k3++;
        }
        else if (a >= l && b >= l)
        {
            v4[k4].id = str;
            v4[k4].morality = a;
            v4[k4].talent = b;
            v4[k4].sum = a + b;
            k4++;
        }
    }
    sort(v1.begin(), v1.begin() + k1, cmp);
    sort(v2.begin(), v2.begin() + k2, cmp);
    sort(v3.begin(), v3.begin() + k3, cmp);
    sort(v4.begin(), v4.begin() + k4, cmp);
    cout << k1 + k2 + k3 + k4 << endl;
    for (int i = 0; i < k1; i++)
        cout << v1[i].id << " " << v1[i].morality << " " << v1[i].talent << endl;
    for (int i = 0; i < k2; i++)
        cout << v2[i].id << " " << v2[i].morality << " " << v2[i].talent << endl;
    for (int i = 0; i < k3; i++)
        cout << v3[i].id << " " << v3[i].morality << " " << v3[i].talent << endl;
    for (int i = 0; i < k4; i++)
        cout << v4[i].id << " " << v4[i].morality << " " << v4[i].talent << endl;
    return 0;
}
