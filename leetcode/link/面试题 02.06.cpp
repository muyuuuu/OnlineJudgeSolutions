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
    bool isPalindrome(ListNode* head) {
        vector<int> v1, v2;
        while (head != nullptr) {
            v1.push_back(head->val);
            head = head->next;
        }
        v2.assign(v1.begin(), v1.end());
        reverse(v1.begin(), v1.end());

        for (auto i = 0; i < v1.size(); i++) {
            if (v1[i] != v2[i])
                return false;
        }

        return true;
    }
};

// 执行用时：12 ms, 在所有 C++ 提交中击败了94.65%的用户
// 内存消耗：14.2 MB, 在所有 C++ 提交中击败了16.93%的用户