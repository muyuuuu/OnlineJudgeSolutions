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
    int minDepth(TreeNode* root) {

        if (root == nullptr)
            return 0;
        deque<TreeNode*> v;
        v.push_back(root);

        int depth = 1;
        while (!v.empty()) {
            int s = v.size();
            for (int i = 0; i < s; i++) {
                TreeNode* node = v.front();
                v.pop_front();
                if (node->left == nullptr && node->right == nullptr) {
                    return depth;
                }
                if (node->left != nullptr)
                    v.push_back(node->left);
                if (node->right != nullptr)
                    v.push_back(node->right);
            }
            depth++;
        }

        return depth;
    }
};

// 执行用时： 256 ms , 在所有 C++ 提交中击败了 20.76% 的用户
// 内存消耗： 141.2 MB , 在所有 C++ 提交中击败了 86.36% 的用户
