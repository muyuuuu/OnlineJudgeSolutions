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
    TreeNode* searchBST(TreeNode* root, int val) {
        TreeNode* node = find(root, val);
        return node;
    }

    TreeNode* find(TreeNode* node, int val) {
        if (node == nullptr)
            return nullptr;
        else if (node->val == val)
            return node;
        else if (node->val < val)
            return find(node->right, val);
        else
            return find(node->left, val);
    }
};

// 执行用时： 32 ms , 在所有 C++ 提交中击败了 91.76% 的用户
// 内存消耗： 34 MB , 在所有 C++ 提交中击败了 38.77% 的用户
