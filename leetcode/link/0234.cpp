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
    bool isPalindrome(ListNode* head) {
        vector<int> v;

        while (head != nullptr) {
            v.push_back(head->val);
            head = head->next;
        }

        vector<int> r;
        r.assign(v.rbegin(), v.rend());

        bool flag{true};
        for (int i = 0; i < v.size(); i++) {
            if (v[i] != r[i]) {
                flag = false;
                break;
            }
        }

        return flag;
    }
};

// 执行用时： 256 ms , 在所有 C++ 提交中击败了 29.97% 的用户
// 内存消耗： 129.3 MB , 在所有 C++ 提交中击败了 5.03% 的用户
