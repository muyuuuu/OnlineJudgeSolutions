#include <iostream>

using namespace std;

struct node
{
    int v;
    struct node *left, *right; 
};

int num[1000] = {0};

node* build(node *root, int v)
{
    if (root == NULL)
    {
        root = new node();
        root->v = v;
        root->left = NULL;
        root->right = NULL;
    }
    else if (v <= root->v)
    {
        root->left = build(root->left, v);
    }
    else
    {
        root->right = build(root->right, v);
    }
    return root;
}

int maxdepth = -1;

void dfs(node *root, int depth)
{
    if (root == NULL)
    {
        if (depth > maxdepth)
            maxdepth = depth;
        return;
    }
    num[depth]++;
    dfs(root->left, depth+1);
    dfs(root->right, depth+1);
}

int main()
{
    int n;
    cin >> n;
    int temp;
    node *root = NULL;
    for (int i = 0; i < n; i++)
    {
        cin >> temp;
        root = build(root, temp);
    }
    dfs(root, 0);
    cout << num[maxdepth - 1] << " + " << num[maxdepth - 2] << " = " << num[maxdepth - 2] + num[maxdepth - 1];
}