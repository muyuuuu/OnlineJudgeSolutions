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
    long long int n = LLONG_MIN;
public:
    bool isValidBST(TreeNode* root) {
        return inorder(root);
    }

    bool inorder(TreeNode* node) {
        if (node == nullptr)
            return true;
        
        if (!inorder(node->left))
            return false;

        if (node->val <= n)
            return false;
        n = node->val;

        return inorder(node->right);
    }
};

// 执行用时： 20 ms , 在所有 C++ 提交中击败了 17.32% 的用户
// 内存消耗： 21.2 MB , 在所有 C++ 提交中击败了 44.72% 的用户
