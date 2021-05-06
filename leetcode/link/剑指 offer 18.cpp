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
    ListNode* deleteNode(ListNode* head, int val) {
        ListNode tmp;
        ListNode* dummy = &tmp;
        dummy->next = head;

        ListNode* prv = dummy;
        ListNode* cur = head;
        while (cur != NULL) {
            if (cur->val == val) {
                // 下一个节点不为空
                if (cur->next != NULL) {
                    prv->next = cur->next;
                }
                else {
                    prv->next = NULL;
                }
            }
            prv = prv->next;
            cur = cur->next;
        }

        return dummy->next;
    }
};

// 执行用时：12 ms, 在所有 C++ 提交中击败了77.14%的用户
// 内存消耗：9.1 MB, 在所有 C++ 提交中击败了34.21%的用户