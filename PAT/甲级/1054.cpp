#include <iostream>
#include <map>
using namespace std;

map<string, int> arr;

int main()
{
    int m, n;
    cin >> m >> n;
    int half = m * n / 2;
    string str; 
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> str;
            arr[str] += 1;
        }
        if (arr[str] > half)
        {
            cout << str;
            return 0;
        }
    }
    return 0;
}