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
    map<vector<int>, int> index;
    vector<TreeNode*> res;
public:
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        int idx{0};
        build(root);
        return res;
    }

    void build(TreeNode* root) {
        if (root == nullptr)
            return;

        vector<int > tmp;
        dfs(root, tmp);
        index[tmp] ++;
        if (index[tmp] == 2)
            res.push_back(root);
        
        build(root->left);
        build(root->right);
    }

    void dfs(TreeNode* node, vector<int>& tmp) {
        if (node == nullptr) {
            tmp.push_back(-10);
            return;
        }
        tmp.push_back(node->val);
        dfs(node->left, tmp);
        dfs(node->right, tmp);
    }
};

// 执行用时： 420 ms , 在所有 C++ 提交中击败了 5.79% 的用户
// 内存消耗： 114.5 MB , 在所有 C++ 提交中击败了 4.99% 的用户
