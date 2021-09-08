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
    const int isBst{0};
    const int minn{1};
    const int maxn{2};
    const int sumv{3};
    int maxsum{0};
public:
    int maxSumBST(TreeNode* root) {
        int* arr = build(root);
        if (maxsum < 0)
            return 0;
        return maxsum;
    }

    int* build(TreeNode* node) {
        if (node == nullptr) {
            int* arr = new int[4]{1, 40005, -40005, 0};
            return arr;
        }
        
        int* left = build(node->left);
        int* right = build(node->right);

        int* res = new int[4];
        if (left[isBst] == 1 && right[isBst] == 1 
            && node->val > left[maxn] && node->val < right[minn]) {
            *(res + isBst) = 1;
            *(res + minn) = min(node->val, left[minn]);
            *(res + maxn) = max(node->val, right[maxn]);
            *(res + sumv) = node->val + left[sumv] + right[sumv];
            maxsum = max(res[sumv], maxsum);
        }
        else {
            res[isBst] = 0;
        }

        return res;
    }
};

// 执行用时： 272 ms , 在所有 C++ 提交中击败了 53.05% 的用户
// 内存消耗： 151.7 MB , 在所有 C++ 提交中击败了 50.27% 的用户
