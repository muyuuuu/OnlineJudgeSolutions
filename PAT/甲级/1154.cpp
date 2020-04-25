#include <iostream>
#include <set>

using namespace std;

struct node
{
    int a;
    int b;
}arr[10004];


int main(int argc, char const *argv[])
{
    int n, m, k;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> arr[i].a >> arr[i].b;
    }
    cin >> k;
    for (int i = 0; i < k; i++)
    {
        int flag = 0;
        set <int> s;
        int color[10004] = {0};
        for (int j = 0; j < n; j++)
        {
            cin >> color[j];
            s.insert(color[j]);
        }
        for (int j = 0; j < m; j++)
        {
            if (color[arr[j].a] == color[arr[j].b])
            {
                flag = 1;
                break;
            }
        }
        if (flag == 1) cout << "No" << endl;
        if (flag == 0) cout << s.size() << "-coloring" << endl;
    }
    return 0;
}
