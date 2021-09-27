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
    ListNode* deleteDuplicates(ListNode* head) {

        if (head == nullptr)
            return nullptr;

        ListNode* slow = head;
        ListNode* fast = head;
        
        while (fast != nullptr) {
            if (slow->val != fast->val) {
                slow->next = fast;
                slow = slow->next;
            }
            fast = fast->next;
        }
        slow->next = nullptr;
        return head;
    }
};

// 执行用时： 12 ms , 在所有 C++ 提交中击败了 56.50% 的用户
// 内存消耗： 11.4 MB , 在所有 C++ 提交中击败了 5.91% 的用户
