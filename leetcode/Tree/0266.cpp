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
public:
    TreeNode* invertTree(TreeNode* root) {
        if (root == nullptr)
            return root;
        
        TreeNode* tmp;
        tmp = root->left;
        root->left = root->right;
        root->right = tmp;

        invertTree(root->right);
        invertTree(root->left);

        return root;
    }
};

// 执行用时： 0 ms , 在所有 C++ 提交中击败了 100.00% 的用户
// 内存消耗： 9.5 MB , 在所有 C++ 提交中击败了 56.20% 的用户
