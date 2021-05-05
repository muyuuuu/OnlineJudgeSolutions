class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;
        while (curr) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
};

// 执行用时：8 ms, 在所有 C++ 提交中击败了66.48%的用户
// 内存消耗：8.1 MB, 在所有 C++ 提交中击败了48.12%的用户