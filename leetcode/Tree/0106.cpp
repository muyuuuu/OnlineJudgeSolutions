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
    unordered_map<int, int> m;
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = inorder.size();
        for (int i = 0; i < n; i++) {
            m[inorder[i]] = i;
        }
        return build(inorder, postorder, 0, n-1, 0, n-1);
    }

    TreeNode* build(vector<int>& inorder, vector<int>& postorder, int il, int ir, int pl, int pr) {
        if (il > ir)
            return nullptr;
        // cout << il << " " << ir << " " << pl << " " << pr << endl;
        int v = postorder[pr];
        TreeNode* root = new TreeNode(v);
        int size = m[v] - il;

        root->left = build(inorder, postorder, il, il+size-1, pl, pl+size-1);
        root->right = build(inorder, postorder, il+size+1, ir, pl+size, pr-1);

        return root;
    }
};

// 执行用时： 24 ms , 在所有 C++ 提交中击败了 62.46% 的用户 
// 内存消耗： 25.8 MB , 在所有 C++ 提交中击败了 38.48% 的用户
