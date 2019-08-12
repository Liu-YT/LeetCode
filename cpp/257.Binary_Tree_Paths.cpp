/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        if(root == nullptr) return ans;
        if(root->left == nullptr && root->right == nullptr) {
            ans.push_back(to_string(root->val));
        }

        vector<string> l = binaryTreePaths(root->left);
        string cur = to_string(root->val) + "->";
        for(auto &s : l) {
            ans.push_back(cur+s);
        }
        vector<string> r = binaryTreePaths(root->right);
        for(auto &s : r) {
            ans.push_back(cur+s);
        }
        return ans;
    }
};