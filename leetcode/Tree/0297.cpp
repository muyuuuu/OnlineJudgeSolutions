/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
private:
    int key{0};
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string res{""};
        preorder(root, res);
        return res;
    }

    void preorder(TreeNode* node, string& s) {
        if (node == nullptr) {
            s += "N";
            s += ' ';
            return;
        }

        s += to_string(node->val);
        s += ' ';
    
        preorder(node->left, s);
        preorder(node->right, s);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {

        stringstream ss(data);
        vector<std::string> tokens;
        string buf; 
        while (ss >> buf)
            tokens.push_back(buf);

        if (tokens.size() == 1 && tokens[0] == "N")
            return nullptr;
        
        TreeNode* root = build(tokens);
        return root;
    }

    TreeNode* build(vector<std::string>& data) {
        if (data[key] == "N") {
            key++;
            return nullptr;
        }
        TreeNode* node = new TreeNode(stoi(data[key++]));
        node->left = build(data);
        node->right = build(data);

        return node;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));

// 执行用时： 40 ms , 在所有 C++ 提交中击败了 87.65% 的用户
// 内存消耗： 34.4 MB , 在所有 C++ 提交中击败了 53.25% 的用户
