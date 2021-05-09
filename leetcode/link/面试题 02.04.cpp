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
    ListNode* partition(ListNode* head, int x) {
        if (head == nullptr)
            return nullptr;
        vector<int> vl;
        vector<int> vr;
        // ListNode* dummy = new ListNode();
        // dummy->next = head;
        auto p = head;
        while (p != nullptr) {
            if (p->val < x)
                vl.push_back(p->val);
            else
                vr.push_back(p->val);
            p = p->next;
        }
        p = head;
        for (auto&i : vl) {
            ListNode* t = new ListNode(i);
            head->next = t;
            head = head->next;
        }
        for (auto& i : vr) {
            ListNode*t = new ListNode(i);
            head->next = t;
            head = head->next;
        }
        head->next = nullptr;
        return p->next;
    }
};

// 执行用时：4 ms, 在所有 C++ 提交中击败了94.10%的用户
// 内存消耗：10.2 MB, 在所有 C++ 提交中击败了5.26%的用户

class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode* small = new ListNode(0);
        ListNode* smallHead = small;
        ListNode* large = new ListNode(0);
        ListNode* largeHead = large;
        while (head != nullptr) {
            if (head->val < x) {
                small->next = head;
                small = small->next;
            } else {
                large->next = head;
                large = large->next;
            }
            head = head->next;
        }
        large->next = nullptr;
        small->next = largeHead->next;
        return smallHead->next;
    }
};

// 执行用时：4 ms, 在所有 C++ 提交中击败了94.10%的用户
// 内存消耗：9.9 MB, 在所有 C++ 提交中击败了40.96%的用户