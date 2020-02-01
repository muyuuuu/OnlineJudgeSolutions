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
    sort(a, a + num - 1);
    // 相对于 1048-2.cpp ， 有一个测试点过不去
    for (int i = 0; i < num; i++)
    {
        for (int j = i + 1; j < num; j++)
        {
            if (a[i] + a[j] == target)
            {
                printf("%d %d", a[i], a[j]);
                return 0;
            }
        }
    }
    cout << "No Solution";
    return 0;
}