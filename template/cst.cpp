#include <iostream>
#include <algorithm>

using namespace std;

int arr[1010], level[1010], n, t{0};

void dfs(int root) {
    if (root >= n)
        return;
    dfs(root * 2 + 1);
    level[root] = arr[t++];
    dfs(root * 2 + 2);
}

int main (){

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    sort(arr, arr + n);
    dfs(0);
    cout << level[0];
    for (int i = 1; i < n; i++)
        printf(" %d", level[i]);
}