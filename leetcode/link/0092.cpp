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
    ListNode* reverseBetween(ListNode* head, int left, int right) {

        if (left == right)
            return head;

        vector<int> v1;
        vector<int> v2;
        
        ListNode* dummy = new ListNode();
        dummy->next = head;
    
        while (head != nullptr) {
            v1.push_back(head->val);
            head = head->next;
        }

        v2.resize(v1.size());
        v2.assign(v1.begin(), v1.end());

        reverse(v2.begin()+left-1, v2.begin() + right);

        ListNode* p = new ListNode();
        dummy->next = p;
        int h;
        for (int i = 1; i <= v1.size(); i++) {
            if (i >= left && i <=right)
                h = v2[i-1];
            else
                h = v1[i-1];
            ListNode* t = new ListNode(h);
            if (i == 1)
                dummy->next = t;
            p->next = t;
            p = t;
        }

        return dummy->next;
    }
};

//执行用时：4 ms, 在所有 C++ 提交中击败了53.16%的用户
//内存消耗：7.5 MB, 在所有 C++ 提交中击败了5.41%的用户
