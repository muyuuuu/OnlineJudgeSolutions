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
    int cnt{0};
public:
    int countNodes(TreeNode* root) {
        return dfs(root);
    }

    int dfs (TreeNode* node) {
        if (node == nullptr)
            return 0;
        return 1 + dfs(node->left) + dfs(node->right);
    }
};

// 执行用时： 32 ms , 在所有 C++ 提交中击败了 66.87% 的用户
// 内存消耗： 30.1 MB , 在所有 C++ 提交中击败了 76.06% 的用户
