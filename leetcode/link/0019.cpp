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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        ListNode* pre = dummy;
        ListNode*p = dummy;

        for (int i = 0; i < n; i++) {
            p = p->next;
        }

        while (p->next != nullptr) {
            pre = pre->next;
            p = p->next;
            head = head->next;
        }
    
        pre->next = head->next;

        return dummy->next;
    }
};

// 执行用时：4 ms, 在所有 C++ 提交中击败了82.37%的用户
// 内存消耗：10.4 MB, 在所有 C++ 提交中击败了49.75%的用户


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
    ListNode* removeNthFromEnd(ListNode* head, int n) {

        ListNode* fast = head;
        while (n > 0) {
            fast = fast->next;
            n--;
        }

        if (fast == nullptr)
            return head->next;

        ListNode* slow = head;
        while(fast->next != nullptr) {
            fast = fast->next;
            slow = slow->next;
        }

        slow->next = slow->next->next;
        return head;
    }
};

// 执行用时： 4 ms , 在所有 C++ 提交中击败了 77.36% 的用户
// 内存消耗： 10.4 MB , 在所有 C++ 提交中击败了 69.39% 的用户
