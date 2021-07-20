#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int W, cnt{0};
int weight[101] = {0};
int temp[101] = {0};
vector<int> res[101], arr[101];

bool cmp(int a, int b) {
    return weight[a] > weight[b];
}

void dfs(int idx, int num, int w) {
    if (w > W)
        return;
    if (w == W) {
        if (arr[idx].size() != 0)
            return;
        else {
            for (int i = 0; i < num; i++)
                res[cnt].push_back(temp[i]);
            cnt++;
            return;
        }
    }
    for (int i = 0; i < arr[idx].size(); i++) {
        int node = arr[idx][i];
        temp[num] = node;
        dfs(node, num+1, w + weight[node]);
    }
}

int main() {
    int n, m, id, t1, t2;
    cin >> n >> m >> W;
    for (int i = 0; i < n; i++) {
        cin >> weight[i];
    }
    for (int i = 0; i < m; i++) {
        cin >> id >> t1;
        for (int j = 0; j < t1; j++) {
            cin >> t2;
            arr[id].push_back(t2);
        }
        sort(arr[id].begin(), arr[id].end(), cmp);
    }
    dfs(0, 1, weight[0]);
    cout << "Has " << cnt << " paths" << endl;
    for (int i = 0; i < cnt; i++) {
        // cout << weight[0];
        for (int j = 0; j < res[i].size(); j++)
            cout << res[i][j] << " ";
        cout << endl;
    }
    return 0;
}