#include <iostream>
#include <stack>

using namespace std;

int arr[1002];

int main(int argc, char const *argv[])
{
    int m, n, k;
    cin >> m >> n >> k;
    for (int j = 0; j < k; j++)
    {
        for (int i = 1; i <= n; i++)
            scanf("%d", &arr[i]);
        int flag = 0, pos = 1;
        stack <int> s;
        flag = 0;
        for (int i = 1; i <= n; i++)
        {
            s.push(i);
            if (s.size() > m) break;
            while (!s.empty() && s.top() == arr[pos])
            {
                s.pop();
                pos += 1;
            }
        }
        if (pos == n + 1) flag = 1;
        if (flag == 1) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}
