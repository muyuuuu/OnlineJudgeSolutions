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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if (l1 == nullptr && l2 == nullptr)
            return nullptr;
        ListNode* p1 = new ListNode(0);
        p1->next = nullptr;
        ListNode* p2 = p1;
        ListNode* front = nullptr;

        while (l1 != nullptr || l2 != nullptr) {
            p1->val += ((l1 == nullptr ? 0 : l1->val) + (l2 == nullptr ? 0 : l2->val));
            // 一定要有指向下一个节点的，尽管是 0，为了进位
            p1->next = new ListNode(p1->val / 10);
            p1->val = p1->val % 10;
            front = p1;
            p1 = p1->next;

            if (l1 != nullptr)
                l1 = l1->next;
            if (l2 != nullptr)
                l2 = l2->next;
        }

        // 5 + 4 会生成 9 0，删除最后一个0
        // 5 + 5 会生成 0 1，不用删除
        if (p1->val == 0){
            delete front->next;
            front->next = nullptr;
        }

        return p2;
    }
};

// 执行用时：24 ms, 在所有 C++ 提交中击败了98.00%的用户
// 内存消耗：69.2 MB, 在所有 C++ 提交中击败了51.34%的用户