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
    int kthSmallest(TreeNode* root, int k) {
        vector<int> res;
        dfs(root, res);
        int t = res[k-1];
        return t;
    }

    void dfs(TreeNode* node, vector<int>& res) {
        if (node == nullptr)
            return;
        dfs(node->left, res);
        res.push_back(node->val);
        dfs(node->right, res);
    }
};

// 执行用时： 24 ms , 在所有 C++ 提交中击败了 26.78% 的用户
// 内存消耗： 23.9 MB , 在所有 C++ 提交中击败了 7.50% 的用户
