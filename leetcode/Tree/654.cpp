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
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return build(nums, 0, nums.size() - 1);
    }

    TreeNode* build (vector<int>& nums, int l, int r) {
        if (l > r)
            return nullptr;
        
        int idx = -1, maxn = INT_MIN;
        for (int i = l; i <= r; i++) {
            if (nums[i] > maxn) {
                maxn = nums[i];
                idx = i;
            }
        }

        TreeNode* root = new TreeNode(maxn);
        root->left = build(nums, l, idx - 1);
        root->right = build(nums, idx + 1, r);

        return root;
    }
};

// 执行用时： 80 ms , 在所有 C++ 提交中击败了 78.10% 的用户
// 内存消耗： 41.2 MB , 在所有 C++ 提交中击败了 66.93% 的用户
