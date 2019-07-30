/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

/* solution 1 */
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> view;
        helper(root, 0, view);
        return view;
    }

    void helper(TreeNode* node, int level, vector<int>& view) {
        if(node == nullptr) return;
        if(level == view.size()) {
            view.push_back(node->val);
        }
        helper(node->right, level + 1, view);
        helper(node->left, level + 1, view);
    }
};

/* solution 2 */
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        if(!root)   return {};
        vector<int> view;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()) {
            int n = q.size();
            for(int i = 0; i < n; i++) {
                TreeNode* temp = q.front();
                q.pop();
                if(i == 0) {
                    view.push_back(temp->val);
                }
                if(temp->right) q.push(temp->right);
                if(temp->left) q.push(temp->left);
            }
        }
        return view;
    }
};