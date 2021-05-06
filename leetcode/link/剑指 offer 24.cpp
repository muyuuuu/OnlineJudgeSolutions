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
    ListNode* reverseList(ListNode* head) {
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;

        ListNode* prv = dummy;
        ListNode* cur = head;

        while (cur) {
            ListNode* nxt = cur->next;
            if (prv == dummy)
                cur->next = NULL;
            else
                cur->next = prv;
            prv = cur;
            cur = nxt;
        }
        if (prv != dummy)
            dummy->next = prv;
        return dummy->next;
    }
};

// 执行用时：8 ms, 在所有 C++ 提交中击败了63.76%的用户
// 内存消耗：8.1 MB, 在所有 C++ 提交中击败了26.38%的用户