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
    ListNode* sortList(ListNode* head) {
        vector<int> v;
        ListNode* p = head;
        while (p != nullptr) {
            v.push_back(p->val);
            p = p->next;
        }
        sort(v.begin(), v.end());
        ListNode* dummy = new ListNode(-1);
        dummy->next = nullptr;
        ListNode* pre = dummy;
        for (auto& i : v) {
            ListNode* q = new ListNode(i);
            dummy->next = q;
            dummy = dummy->next;
        }
        return pre->next;
    }
};

// 执行用时：116 ms, 在所有 C++ 提交中击败了74.58%的用户
// 内存消耗：32.9 MB, 在所有 C++ 提交中击败了46.27%的用户