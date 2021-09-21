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
    ListNode *detectCycle(ListNode *head) {
        
        ListNode* fast = head;
        ListNode* slow = head;

        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;

            if (fast == slow)
                break;
        }

        if (fast == nullptr || fast->next == nullptr)
            return nullptr;

        slow = head;
        while (fast != slow) {
            slow = slow->next;
            fast = fast->next;
        }

        return fast;

    }
};

// 执行用时： 8 ms , 在所有 C++ 提交中击败了 82.33% 的用户
// 内存消耗： 7.4 MB , 在所有 C++ 提交中击败了 75.45% 的用户
