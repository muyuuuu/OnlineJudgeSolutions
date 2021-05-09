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
    ListNode* removeDuplicateNodes(ListNode* head) {
        unordered_map<int, int> m;
        auto p = head;
        ListNode* pre = new ListNode(-1);
        ListNode* dummy = new ListNode(-1);
        pre->next = head;
        int flag{0};
        while (p != nullptr) {
            if (m[p->val] != 1) {
                m[p->val] = 1;
                pre->next = p;
                if (flag == 0) {
                    dummy->next = p;
                    flag = 1;
                }
                pre = pre->next;
            }
            else
                pre->next = nullptr;
            p = p->next;
        }
        return dummy->next;
    }
};

// 执行用时：32 ms, 在所有 C++ 提交中击败了90.61%的用户
// 内存消耗：16 MB, 在所有 C++ 提交中击败了61.83%的用户