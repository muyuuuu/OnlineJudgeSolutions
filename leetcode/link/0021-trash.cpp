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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode();
        ListNode* p = dummy;
        while (l1 != nullptr || l2 != nullptr) {
            if (l1 == nullptr && l2 != nullptr) {
                while (l2 != nullptr) {
                    p->next = l2;
                    l2 = l2->next;
                    p = p->next;
                }
            }
            else if (l1 != nullptr && l2 == nullptr) {
                while (l1 != nullptr) {
                    p->next = l1;
                    l1 = l1->next;
                    p = p->next;
                }
            }
            else if (l1 != nullptr && l1 != nullptr ) {
                if (l1->val <= l2->val) {
                    p->next = l1;
                    l1 = l1->next;
                    p = p->next;
                }
                else {
                    p->next = l2;
                    l2 = l2->next;
                    p = p->next;
                }
            }
        }
        return dummy->next;
    }
};

// 执行用时：16 ms, 在所有 C++ 提交中击败了16.57%的用户
// 内存消耗：14.3 MB, 在所有 C++ 提交中击败了90.60%的用户