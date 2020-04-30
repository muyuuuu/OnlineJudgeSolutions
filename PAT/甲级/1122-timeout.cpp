#include <iostream>
#include <vector>
#include <set>

using namespace std;

vector <int> arr[203];

int main(int argc, char const *argv[])
{
    int n, m, k, a, b;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b;
        arr[a].push_back(b);
        arr[b].push_back(a);
    }
    cin >> k;
    set <int> s;
    for (int i = 0; i < k; i++)
    {
        cin >> m;
        s.clear();
        int j = 0, count = 0, flag1 = 0, head = 0, tail = 0;
        while (j < m)
        {
            j++;
            cin >> a;
            // 先查找
            if (count != 0)
            {
                // 没找到
                if (s.find(a) == s.end())
                {
                    flag1 = 1;
                }
            }
            // 清空集合
            s.clear();
            for (auto it : arr[a])
                s.insert(it);
            count += 1;
            if (j == 1)
                head = a;
            if (j == m) 
                tail = a;
        }
        if (flag1 == 1) cout << "NO" << endl;
        else if (head != tail) cout << "NO" << endl;
        else if (count == n + 1) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}

