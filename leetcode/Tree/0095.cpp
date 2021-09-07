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
    vector<TreeNode*> generateTrees(int n) {
        return build(1, n);
    }

    vector<TreeNode*> build(int l, int h) {
        if (l > h) {
            return {nullptr};
        }

        vector<TreeNode*> res;

        for (int i = l; i <= h; i++) {
            auto left = build(l, i-1);
            auto right = build(i+1, h);
            for (auto&k : left) {
                for (auto&j : right) {
                    TreeNode* root = new TreeNode(i);
                    root->left = k;
                    root->right = j;
                    res.push_back(root);
                }
            }
        }

        return res;
    }
};

// 执行用时： 16 ms , 在所有 C++ 提交中击败了 87.40% 的用户
// 内存消耗： 15.7 MB , 在所有 C++ 提交中击败了 62.95% 的用户
