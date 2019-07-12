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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        sol(root, 0, res);
        return res;
    }

    void sol(TreeNode* node, int level, vector<vector<int>> &res) {
        if(node == NULL) return;
        if(res.size() > level) {
            res[level].push_back(node->val);
        } else {
            res.push_back({node->val});
        }
        sol(node->left, level + 1, res);
        sol(node->right, level + 1, res);
    }

};

/* solution 2 */
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(root == NULL)    return {};
        vector<vector<int>> res;
        queue<pair<TreeNode*, int>> q;
        q.push(make_pair(root, 0));
        
        while(!q.empty()) {
            TreeNode* node = q.front().first;
            int level = q.front().second;
            q.pop();
            if(res.size() > level) {
                res[level].push_back(node->val);
            } else {
                res.push_back({node->val});
            }
        
            if(node->left)
                q.push(make_pair(node->left, level+1));
            
            if(node->right)
                q.push(make_pair(node->right, level+1));
        }

        return res;
    }
};