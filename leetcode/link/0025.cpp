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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (head == nullptr)
            return nullptr;
        ListNode* a = head;
        ListNode* b = head;

        for (int i = 0; i < k; i++) {
            if (b == nullptr)
                return head;
            b = b->next;
        }
        ListNode* newhead = reverse(a, b);
        a->next = reverseKGroup(b, k);
        return newhead;
    }

    ListNode* reverse(ListNode* a, ListNode* b) {
        ListNode* pre = nullptr;
        ListNode* cur = a;
        ListNode* next = a;

        while (cur != b) {
            next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
        }

        return pre;
    }
};

// 执行用时： 24 ms , 在所有 C++ 提交中击败了 11.86% 的用户 
// 内存消耗： 11.1 MB , 在所有 C++ 提交中击败了 93.22% 的用户
