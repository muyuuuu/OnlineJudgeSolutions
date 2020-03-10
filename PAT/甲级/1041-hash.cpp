#include <iostream>
#include <vector>

using namespace std;

int arr[10004];

vector<int> v;

int main(int argc, char const *argv[])
{
    int n, a, flag = 0;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a;
        arr[a] ++;
        v.push_back(a);
    }
    for (int i = 0; i < v.size(); i++)
    {
        if (arr[v[i]] == 1)
        {
            flag = 1;
            cout << v[i];
            return 0;
        }
    }
    if (flag == 0) cout << "None";
    return 0;
}
