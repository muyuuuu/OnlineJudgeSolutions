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
    void flatten(TreeNode* root) {
        if (root == nullptr)
            return;
        
        flatten(root->left);
        flatten(root->right);

        TreeNode* l = root->left;
        TreeNode* r = root->right;

        root->right = l;
        root->left = nullptr;

        TreeNode* p = root;
        while (p->right != nullptr) 
            p = p->right;
        p->right = r;

    }
};

// 执行用时： 8 ms , 在所有 C++ 提交中击败了 60.61% 的用户 
// 内存消耗： 12.3 MB , 在所有 C++ 提交中击败了 83.55% 的用户
