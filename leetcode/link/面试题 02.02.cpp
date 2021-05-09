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
    int kthToLast(ListNode* head, int k) {
        auto p1 = head;
        auto p2 = head;
        for (int i = 0; i < k; i++) {
            p1 = p1->next;
        }
        while (p1 != NULL) {
            p1 = p1->next;
            p2 = p2->next;
        }

        return p2->val;
    }
};

// 执行用时：4 ms, 在所有 C++ 提交中击败了64.72%的用户
// 内存消耗：10.1 MB, 在所有 C++ 提交中击败了75.68%的用户