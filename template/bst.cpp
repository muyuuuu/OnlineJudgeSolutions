#include <iostream>

using namespace std;

struct node {
    int v;
    struct node* left;
    struct node* right;
};
int maxdepth = -1;
int num[1000] = {0};

node* build (node* root, int v) {
    if (root == nullptr) {
        root = new node();
        root->v = v;
        root->left = nullptr;
        root->right = nullptr;
    }
    else if (root->v >= v) {
        root->left = build(root->left, v);
    }
    else {
        root->right = build(root->right, v);
    }
    return root;
}

void dfs(node *root, int depth)
{
    if (root == NULL) {
        if (depth > maxdepth)
            maxdepth = depth;
        return;
    }
    num[depth]++;
    dfs(root->left, depth+1);
    dfs(root->right, depth+1);
}

int main (){

    int n, t;
    cin >> n;
    node* root = nullptr;
    for (int i = 0; i < n; i++) {
        cin >> t;
        root = build(root, t);
    }
    dfs(root, 0);
    cout << num[maxdepth - 1] << " + " << num[maxdepth - 2] << " = " << num[maxdepth - 2] + num[maxdepth - 1];

    return 0;
}