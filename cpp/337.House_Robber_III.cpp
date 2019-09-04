/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// time limit
class Solution {
public:
    unordered_map<TreeNode*, int> m;
    int rob(TreeNode* root) {
        if(root == nullptr)
            return 0;

        if(m.count(root))
            return m[root];
        // rob cur
        int ans = root->val;
        if(root->left != nullptr) 
            ans += rob(root->left->left) + rob(root->left->right);
        if(root->right != nullptr) 
            ans += rob(root->right->left) + rob(root->right->right);

        ans = max(ans, rob(root->left) + rob(root->right));
        m[root] = ans;
        return ans;
    }
};