/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) {
        node->val = node->next->val;
        node->next = node->next->next;
    }
};

// 执行用时：12 ms, 在所有 C++ 提交中击败了58.42%的用户
// 内存消耗：7.5 MB, 在所有 C++ 提交中击败了33.24%的用户