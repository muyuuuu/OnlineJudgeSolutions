#include <iostream>
#include <map>

using namespace std;

map<int, int> m;

int main(int argc, char const *argv[])
{
    int n, temp, flag = 0;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> temp;
        m[temp] = 1;
    }
    for (int i = 1; i <= n; i++)
    {
        if (m[i] == 0)
        {
            flag = 1;
            cout << i;
            return 0;
        }
    }
    if (flag == 0)
        cout << n + 1 ;
    return 0;
}
