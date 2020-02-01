#include <iostream>
#include <algorithm>

using namespace std;

int a[1005];

int main()
{
    int num, target;
    cin >> num >> target;
    for (int i = 0; i < num; i++)
    {
        scanf("%d", &a[i]);
    }
    sort(a, a + 1005);
    for (int i = 0; i < 1005; i++)
    {
        if (a[i] == 0)
            continue;
        for (int j = i + 1; j < 1005; j++)
        {
            if (a[j] == 0)
                continue;
            if (a[i] + a[j] == target)
            {
                printf("%d %d", a[i], a[j]);
                return 0;
            }
        }
    }
    cout << "No Solution";
    return 0;
}1