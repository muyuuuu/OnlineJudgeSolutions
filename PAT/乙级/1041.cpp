#include <iostream>
#include <vector>

using namespace std;

struct node
{
    string id;
    int shiji;
    int kaoshi;
};

vector <node> v;

int main(int argc, char const *argv[])
{
    int n;
    node temp1;
    v.resize(0);
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> temp1.id >> temp1.shiji >> temp1.kaoshi;
        v.push_back(temp1);
    }
    int m, temp;
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> temp;
        for (int j = 0; j < n; j++)
        {
            if (v[j].shiji == temp)
            {
                cout << v[j].id << " " << v[j].kaoshi << endl;
                break;
            }
        }
    }
    return 0;
}
