#include <iostream>

using namespace std;

struct node
{
    int v;
    struct node *left, *right; 
};

int arr[1002], arr1[1002], arr2[1002];
int key1 = 0, key2 = 0;

// 建立查找树
node* build(node *root, int v)
{
    if (root == NULL)
    {
        root = new node();
        root->v = v;
        root->left = NULL;
        root->right = NULL;
    }
    else if (v < root->v)
    {
        root->left = build(root->left, v);
    }
    else
    {
        root->right = build(root->right, v);
    }
    return root;
}

// 先序遍历
void preorder(node *root, int flag)
{
    if (root != NULL)
    {
        if (flag == 0)
            cout << root->v << " ";
        if (flag == 1)
            arr2[key2++] = root->v;
        // 左 右遍历
        preorder(root->left, flag);
        preorder(root->right, flag);
    }
}


int main(int argc, char const *argv[])
{   
    int n, temp, flag = 0;
    cin >> n;
    node *root = NULL;
    for (int i = 0; i < n; i++)
    {
        cin >> temp;
        arr[i] = temp;
        // 便于遍历时寻找节点
        root = build(root, temp);
    }
    preorder(root, flag);
}
