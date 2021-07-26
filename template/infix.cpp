#include <iostream>
using namespace std;

struct node {
    string data{0};
    int l{-1};
    int r{-1};
} arr[25];

string dfs(int idx) {
    if (arr[idx].l == -1 && arr[idx].r == -1)
        return arr[idx].data;
    if (arr[idx].l == -1 && arr[idx].r != -1)
        return "(" + arr[idx].data + dfs(arr[idx].r) + ")";
    if (arr[idx].l != -1 && arr[idx].r != -1)
        return "(" + dfs(arr[idx].l) + arr[idx].data + dfs(arr[idx].r) + ")";
}

int main (){
    int n, a, b, root;
    string d;
    int tmp[25] = {0};
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> d >> a >> b;
        arr[i].data = d;
        arr[i].l = a;
        arr[i].r = b;
        tmp[a] = 1;
        tmp[b] = 1;
    }
    for (int i = 1; i <= n; i++) {
        if (tmp[i] == 0) {
            root = i;
            break;
        }
    }
    string ans = dfs(root);
    if(ans[0] == '(') 
        ans = ans.substr(1, ans.size()-2);
    cout << ans;
    return 0;
}