#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct node {
    int idx{-1};
    int left{-1};
    int right{-1};
    int layer{0};
};
vector<node> res[20];
int level[20];

void bfs(int root) {
    queue<node> q;
    q.push(res[root][0]);
    while (!q.empty()) {
        node t = q.front();
        q.pop();
        cout << t.idx << " ";
        int layer = t.layer;
        level[layer]++;
        if (t.left != -1) {
            res[t.left][0].layer = layer + 1;
            q.push(res[t.left][0]);
        }
        if (t.right != -1) {
            res[t.right][0].layer = layer + 1;
            q.push(res[t.right][0]);
        }
    }
}

int main (){

    int n;
    cin >> n;
    node t;
    for (int i = 0; i < n; i++) {
        t.idx = i;
        cin >> t.left >> t.right;
        res[i].push_back(t);
    }
    bfs(0);
    cout << endl;
    for (int i = 0; i < 20; i++) {
        if (level[i] != 0)
            cout << level[i] << " ";
    }
    return 0;
}