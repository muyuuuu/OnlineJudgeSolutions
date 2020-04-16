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
            arr1[key1++] = root->v;
        if (flag == 1)
            arr2[key2++] = root->v;
        // 左 右遍历
        preorder(root->left, flag);
        preorder(root->right, flag);
    }
}

int pos1 = 0;
// 后序遍历
void postorder(node *root)
{
    if (root != NULL)
    {
        postorder(root->left);
        postorder(root->right);
        if (pos1 == 0)
        {
            pos1 = 1;
            cout << root->v;
        }
        else
            cout << " " << root->v;
    }
}

// 建立镜像查找树
node* build_image(node *root, int v)
{
    if (root == NULL)
    {
        root = new node();
        root->v = v;
        root->left = NULL;
        root->right = NULL;
    }
    else if (v >= root->v)
    {
        root->left = build_image(root->left, v);
    }
    else
    {
        root->right = build_image(root->right, v);
    }
    return root;
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
        root = build(root, temp);
    }
    preorder(root, flag);
    for (int i = 0; i < n; i++)
    {
        if (arr[i] != arr1[i])
        {
            flag = 1;
            break;
        }
    }
    if (flag == 0)
    {
        cout << "YES" << endl;
        postorder(root);
        return 0;
    }
    root = NULL;
    for (int i = 0; i < n; i++)
    {
        root = build_image(root, arr[i]);
    }
    preorder(root, flag);
    for (int i = 0; i < n; i++)
    {
        if (arr[i] != arr2[i])
        {
            flag = 2;
            break;
        }
    }
    if (flag == 1)
    {
        cout << "YES" << endl;
        postorder(root);
        return 0;   
    }
    cout << "NO";
    return 0;
}
