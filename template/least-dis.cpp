#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

vector<int> res[100005];
int n, num{0}, level{100005};

void dfs(int idx, int depth) {
    if (res[idx].size() == 0) {
        if (level == depth) {
            num++;
        }
        if (depth < level) {
            level = depth;
            num = 1;
        }
    }
    for (int i = 0; i < res[idx].size(); i++) {
        dfs(res[idx][i], depth+1);
    }
}

int main() {
    int m, t;
    double p, r;
    cin >> n >> p >> r;
    r /= 100;
    for (int i = 0; i < n; i++) {
        cin >> m;
        for (int j = 0; j < m; j++) {
            cin >> t;
            res[i].push_back(t);
        }
    }
    dfs(0, 0);
    printf("%.4f ", p * pow(1 + r, level));
    cout << num;
    return 0;
}