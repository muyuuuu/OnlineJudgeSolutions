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
        unordered_map<ListNode*, int> m;
        ListNode* p = head;
        while (p != NULL) {
            if (m[p] != 0)
                return p;
            m[p] = 2;
            p = p->next;
        }
        return nullptr;
    }
};

// 执行用时：16 ms, 在所有 C++ 提交中击败了26.39%的用户
// 内存消耗：9.8 MB, 在所有 C++ 提交中击败了5.29%的用户

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        unordered_set<ListNode *> visited;
        while (head != nullptr) {
            if (visited.count(head)) {
                return head;
            }
            visited.insert(head);
            head = head->next;
        }
        return nullptr;
    }
};

// 执行用时：20 ms, 在所有 C++ 提交中击败了15.16%的用户
// 内存消耗：9.3 MB, 在所有 C++ 提交中击败了18.53%的用户