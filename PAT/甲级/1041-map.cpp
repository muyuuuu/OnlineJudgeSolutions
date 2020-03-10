#include <iostream>
#include <map>

using namespace std;

int arr[100005];

map<string, int> m;

int main(int argc, char const *argv[])
{
    int n, flag = 0;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        m[to_string(arr[i])] ++;
    }
    for (int i = 0; i < n; i++)
    {
        if (m[to_string(arr[i])] == 1)
        {
            flag = 1;
            cout << arr[i];
            return 0;
        }
    }
    if (flag == 0) cout << "None";
    return 0;
}
