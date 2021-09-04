/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
    unordered_map<int, int> index;
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = inorder.size();
        for (int i = 0; i < n; i++)
            index[inorder[i]] = i;
        return build(preorder, inorder, 0, n-1, 0, n-1);
    }
    TreeNode* build(vector<int>& preorder, vector<int>& inorder, int pl, int pr, int il, int ir) {
        if (pl > pr)
            return nullptr;

        int root = preorder[pl];
        TreeNode* node = new TreeNode(root);
        int size = index[root] - il;
        // pl+1, pl+size 是前序遍历中左子树的元素
        // il, il+size-1 是中序遍历中左子树的元素
        node->left = build(preorder, inorder, pl+1, pl+size, il, il+size-1);
        node->right = build(preorder, inorder, pl+1+size, pr, index[root]+1, ir);

        return node;
    }
};

// 执行用时： 12 ms , 在所有 C++ 提交中击败了 92.56% 的用户
// 内存消耗： 25.7 MB , 在所有 C++ 提交中击败了 44.58% 的用户
