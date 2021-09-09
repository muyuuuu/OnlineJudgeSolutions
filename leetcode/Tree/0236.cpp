/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
private:
    TreeNode* res = nullptr;
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        int* arr = build(root, p, q);
        return res;
    }

    int* build(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == nullptr) {
            int* a = new int[1]{0};
            return a;
        }
        int* l = build(root->left, p, q);
        int* r = build(root->right, p, q);

        int* c = new int[1]{0};
        if (root->val == p->val || root->val == q->val)
            c[0] = 1;
        c[0] += l[0] + r[0];

        if (c[0] == 2 && res == nullptr) 
            res = root;
        return c;
    }
};

// 执行用时： 28 ms , 在所有 C++ 提交中击败了 13.46% 的用户
// 内存消耗： 18.8 MB , 在所有 C++ 提交中击败了 5.00% 的用户
