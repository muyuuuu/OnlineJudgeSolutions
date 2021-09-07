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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if (root == nullptr) {
            TreeNode* a = new TreeNode(val);
            return a; 
        }
        build(root, nullptr, val);
        return root;
    }

    void build(TreeNode* node, TreeNode* parent, int val) {
        if (node == nullptr) {
            TreeNode* a = new TreeNode(val);
            if (parent->val < val)
                parent->right = a;
            else 
                parent->left = a;
        }
        else if (node->val > val)
            build(node->left, node, val);
        else
            build(node->right, node, val);
    }
};

// 执行用时： 96 ms , 在所有 C++ 提交中击败了 46.95% 的用户
// 内存消耗： 55.6 MB , 在所有 C++ 提交中击败了 31.35% 的用户
