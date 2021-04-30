class Solution {
public:
    vector<int> nextLargerNodes(ListNode* head) {
        stack<int> st;
        vector<int> temp;
        while(head != NULL){
            temp.push_back(head->val);
            head = head->next;  
        } 
        vector<int> res(temp.size(), 0);
        for(int i = 0; i < temp.size(); i++){
            while(!st.empty() && temp[st.top()] < temp[i]){
                res[st.top()] = temp[i];
                st.pop();
            }
            st.push(i);
       }
       return res;
    }
};

// 执行用时：84 ms, 在所有 C++ 提交中击败了97.16%的用户
// 内存消耗：42.1 MB, 在所有 C++ 提交中击败了18.73%的用户