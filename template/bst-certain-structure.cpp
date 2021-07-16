#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct node {
    int l{-2};
    int r{-2};
};

int arr[105], n{0}, cnt{0}, max_depth{-10};
node arr1[105];
vector<int> level[105], res[105];

void build(int idx) {
    if (idx > n)
        return;
    if (arr1[idx].l != -1)
        build(arr1[idx].l);
    res[idx].push_back(arr[cnt++]);
    if (arr1[idx].r != -1)
        build(arr1[idx].r);
}

void dfs(int idx, int depth) {
    if (depth > max_depth)
        max_depth = depth;
    if (idx > n || res[idx].size() == 0)
        return ;
    level[depth].push_back(res[idx][0]);
    if (arr1[idx].l != -1)
        dfs(arr1[idx].l, depth+1);
    if (arr1[idx].r != -1)
        dfs(arr1[idx].r, depth+1);
}

int main (){

    int a, b;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        arr1[i].l = a;
        arr1[i].r = b;
    }
    for (int i = 0; i < n; i++) {
        cin >> a;
        arr[i] = a;
    }
    sort(arr, arr + n);
    build(0);
    dfs(0, 0);
    int flag = 0;
    for (int i = 0; i < n; i++)
        if (level[i].size() != 0)
            for (int j = 0; j < level[i].size(); j++) {
                if (flag == 0) {
                    flag = 1;
                    cout << level[i][j];
                }
                else
                    cout << " " << level[i][j];
            }
    return 0;
}