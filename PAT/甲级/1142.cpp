#include <iostream>
#include <vector>

using namespace std;

int edge[210][210];

int main(int argc, char const *argv[])
{
    int m, k, v, e, a, b, flag = 0, flag1 = 0;
    cin >> v >> e;
    for (int i = 0; i < e; i++)
    {
        cin >> a >> b;
        edge[a][b] = 1;
        edge[b][a] = 1;
    }
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        int hash[210] = {0};
        flag = 0;
        flag1 = 0;
        cin >> k;
        vector<int> arr;
        arr.clear();
        arr.resize(0);
        for (int j = 0; j < k; j++)
        {
            cin >> a;
            arr.push_back(a);
            hash[a] = 1;
        }
        // 判断不是
        for (int j = 0; j < k; j++)
        {
            if (flag == 1)
                break;
            for (int l = j + 1; l < k; l++)
            {
                if (edge[arr[j]][arr[l]] == 0)
                {
                    flag = 1;
                    cout << "Not a Clique" << endl;
                    break;
                }
            }
        }
        if (flag == 1)
            continue;
        for (int j = 1; j <= v; j++)
        {
            if (hash[j] == 0)
            {
                for (int l = 0; l < k; l++)
                {
                    if (edge[j][arr[l]] == 0)
                        break;
                    // 前方的线都能连上
                    if (l == k - 1)
                        flag1 = 1;
                }
            }
        }
        if (flag1 == 1)
            cout << "Not Maximal" << endl;
        else
            cout << "Yes" << endl;
    }
    return 0;
}


