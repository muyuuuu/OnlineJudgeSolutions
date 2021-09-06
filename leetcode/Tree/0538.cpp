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
    TreeNode* convertBST(TreeNode* root) {
        int sum{0};
        build(root, sum);
        return root;
    }
    
    void build(TreeNode* node, int& sum) {
        if (node == nullptr)
            return;
        build(node->right, sum);
        sum += node->val;
        node->val = sum;
        build(node->left, sum);
    }
};

// 执行用时： 52 ms , 在所有 C++ 提交中击败了 16.43% 的用户
// 内存消耗： 32.6 MB , 在所有 C++ 提交中击败了 55.94% 的用户
