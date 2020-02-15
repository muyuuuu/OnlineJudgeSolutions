#include <iostream>

using namespace std;

int arr[105] = {0};

int main(int argc, char const *argv[])
{
    int n, temp;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> temp;
        arr[temp]++;
    }
    int m;
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> temp;
        if (i == 0)
            cout << arr[temp];
        else
            cout << " " << arr[temp];
    }
    return 0;
}
