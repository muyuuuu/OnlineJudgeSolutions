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
    ListNode* p1;
    int res;

    Solution(ListNode* head) {
        p1 = head;
    }
    
    int getRandom() {
        res = 0;
        ListNode* p = p1;
        int cnt{0};
        while (p != nullptr) {
            if (rand() % (++cnt) == 0) {
                res = p->val;
            }
            p = p->next;
        }

        return res;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */

// 执行用时： 24 ms , 在所有 C++ 提交中击败了 54.37% 的用户
// 内存消耗： 16.1 MB , 在所有 C++ 提交中击败了 82.40% 的用户
