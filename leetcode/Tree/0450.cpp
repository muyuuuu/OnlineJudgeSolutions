/**
 * Definition for a binary tree node->
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
    int getVal(TreeNode* node) {
        node = node->right;
        while (node->left != nullptr) {
            node = node->left;
        }
        return node->val;
    }

    TreeNode* deleteNode(TreeNode* root, int key) {
        if (root == nullptr)
            return nullptr;

        else if (root->val == key) {
            if (root->left == nullptr) {
                return root->right;
            }
            else if (root->right == nullptr) {
                return root->left;
            }
            else {
                root->val = getVal(root);
                root->right = deleteNode(root->right, root->val);
            }
        }

        else if (root->val < key) {
            root->right = deleteNode(root->right, key);
        }

        else if (root->val > key) {
            root->left = deleteNode(root->left, key);
        }

        return root;
    }
};

// 执行用时： 36 ms , 在所有 C++ 提交中击败了 61.56% 的用户
// 内存消耗： 31.9 MB , 在所有 C++ 提交中击败了 46.80% 的用户
