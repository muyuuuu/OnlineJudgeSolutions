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
    ListNode* getKthFromEnd(ListNode* head, int k) {
        ListNode* p = head;
        for (int i = 0; i < k-1; i++) {
            head = head->next;
        }
        while (head->next != NULL) {
            head = head->next;
            p = p->next;
        }
        return p;
    }
};

// 执行用时：4 ms, 在所有 C++ 提交中击败了76.52%的用户
// 内存消耗：10.3 MB, 在所有 C++ 提交中击败了50.79%的用户