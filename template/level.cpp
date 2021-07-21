#include <iostream>
#include <vector>

using namespace std;

int level[105] = {0}, n;
vector<int> arr[105];

void dfs(int idx, int depth) {
    if (idx > n)
        return;
    level[depth] ++;
    for (int i = 0; i < arr[idx].size(); i++)
        dfs(arr[idx][i], depth+1);
}

int main (){
    int m, id, k, a;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> id >> k;
        for (int j = 0; j < k; j++) {
            cin >> a;
            arr[id].push_back(a);
        }
    }
    dfs(1, 1);
    int maxn = -1, num = -1;
    for (int i = 1; i < 105; i++) {
        if (level[i] > num) {
            maxn = i;
            num = level[i];
        }
    }

    cout << num << " " << maxn;
    return 0;
}