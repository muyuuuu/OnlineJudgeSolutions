/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if (root == nullptr)
            return nullptr;
        run(root->left, root->right);
        return root;
    }
    
    void run(Node* t1, Node* t2) {
        if (t1 == nullptr || t2 == nullptr)
            return;
        
        t1->next = t2;

        run(t1->left, t1->right);
        run(t2->left, t2->right);
        run(t1->right, t2->left);
    }
};

//执行用时： 16 ms , 在所有 C++ 提交中击败了 94.00% 的用户
//内存消耗： 16.4 MB , 在所有 C++ 提交中击败了 82.81% 的用户
