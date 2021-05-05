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
    ListNode* reverseList(ListNode* head) {
        int cnt{0};
        ListNode* dummy = new ListNode();
        dummy->next = head;
        ListNode* p = head;
        while (p != nullptr) {
            cnt++;
            p = p->next;
        }
        p = head;
        vector<int> v(cnt, 0);
        cnt = 0;
        while (p != nullptr) {
            v[cnt++] = p->val;
            p = p->next;
        }
        reverse(v.begin(), v.end());
        p = dummy;
        for (auto& i : v) {
            ListNode* p1 = new ListNode();
            p1->val = i;
            p->next = p1;
            p = p->next;
        }
        return dummy->next;
    }
};

// 执行用时：8 ms, 在所有 C++ 提交中击败了66.48%的用户
// 内存消耗：8.4 MB, 在所有 C++ 提交中击败了5.11%的用户