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
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string ans = "";
        if(root == nullptr) {
            ans = "#";
        }
        else {
            ans = to_string(root->val) + ",";
            ans += serialize(root->left);
            ans += serialize(root->right);
        }
        return ans;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        index = 0;
        return decode(data);
    }

    TreeNode* decode(string &data) {
        if(data[index] == '#') {
            ++index;
            return nullptr;
        }

        int num = 0, flag = 1;
        while(data[index] != ',') {
            if(data[index] == '-') {
                flag = -1;
            }
            else {
                num = num * 10 + (data[index] - '0');
            }
            ++index;
        }
        ++index;
        TreeNode* root = new TreeNode(num * flag);
        root->left = decode(data);
        root->right = decode(data);
        return root;
    }
private:
    int index;
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));