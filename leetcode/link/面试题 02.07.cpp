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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* p = nullptr;
        ListNode *node1 = headA;
        ListNode *node2 = headB;
        while (node1 != nullptr || node2 != nullptr) {
            if (node1 == node2){
                p = node1;
                break;
            }
            node1 = node1 != NULL ? node1->next : headB;
            node2 = node2 != NULL ? node2->next : headA;
        }
        return p;
    }
};

// 执行用时：56 ms, 在所有 C++ 提交中击败了41.15%的用户
// 内存消耗：14.1 MB, 在所有 C++ 提交中击败了93.90%的用户