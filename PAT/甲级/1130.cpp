#include <iostream>

using namespace std;

struct node
{
    string data;
    int left = -1;
    int right = -1;
}arr[25];

int tmp[25] = {0}, n, flag = 0;
string ans = "";

string dfs(int root)
{
    if(arr[root].left == -1 && arr[root].right == -1) 
        return arr[root].data;
    if(arr[root].left == -1 && arr[root].right != -1)  
        return "(" +  arr[root].data + dfs(arr[root].right) + ")";
    if(arr[root].left != -1 && arr[root].right != -1) 
        return "(" +  dfs(arr[root].left) + arr[root].data + dfs(arr[root].right) + ")";
}

int main(int argc, char const *argv[])
{
    int l, r, root;
    cin >> n;
    string s;
    for (int i = 1; i <= n; i++)
    {
        cin >> s >> l >> r;
        arr[i].data = s;
        arr[i].left = l;
        arr[i].right = r;
        tmp[l] = 1;
        tmp[r] = 1;
    }
    for (int i = 1; i <= n; i++)
        if (tmp[i] == 0)
            root = i;
    ans = dfs(root);
    if(ans[0] == '(') 
        ans = ans.substr(1,ans.size()-2);
    cout << ans;
    return 0;
}
