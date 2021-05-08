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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        unordered_map<ListNode*, int> m;
        int cnt{1};
        ListNode* p1 = headA;
        while(p1 != nullptr) {
            m[p1] = cnt++;
            p1 = p1->next;
        }
        ListNode* p2 = headB;
        while (p2 != nullptr) {
            if (m[p2] != 0) {
                return p2;
            }
            p2 = p2->next;
        }
        return nullptr;
    }
};

// 执行用时：68 ms, 在所有 C++ 提交中击败了18.11%的用户
// 内存消耗：20.5 MB, 在所有 C++ 提交中击败了5.01%的用户

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *node1 = headA;
        ListNode *node2 = headB;
        
        while (node1 != node2) {
            node1 = node1 != NULL ? node1->next : headB;
            node2 = node2 != NULL ? node2->next : headA;
        }
        return node1;
    }
};

// 执行用时：48 ms, 在所有 C++ 提交中击败了85.25%的用户
// 内存消耗：14.3 MB, 在所有 C++ 提交中击败了43.74%的用户