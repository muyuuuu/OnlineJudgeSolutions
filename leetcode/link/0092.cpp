/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* dummy = new ListNode{0};
        dummy->next = head;

        right -= left;
        ListNode* hh = dummy;
        while (left > 1) {
            left--;
            hh = hh->next;
        }

        ListNode* prv = hh->next;
        ListNode* cur = prv->next;

        while (right > 0) {
            ListNode* nxt = cur->next;
            cur->next = prv;
            prv = cur;
            cur = nxt;
            right--;
        }

        hh->next->next = cur;
        hh->next = prv;

        return dummy->next;
    }
};

// 执行用时：0 ms, 在所有 C++ 提交中击败了100.00%的用户
// 内存消耗：7.1 MB, 在所有 C++ 提交中击败了97.48%的用户