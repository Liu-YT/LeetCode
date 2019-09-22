/*
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};
*/
class Solution {
public:
    vector<vector<int> > Print(TreeNode* pRoot) {
        vector<vector<int>> ans;
        if(pRoot == nullptr) {
            return ans;
        }

        traverse(pRoot, 1, ans);
        
        return ans;
    }

    void traverse(TreeNode* root, int level, vector<vector<int>> &ans) {
        if(root == nullptr) {
            return;
        }

        if(level > ans.size()) {
            ans.push_back(vector<int>());
        }

        // left
        if(level % 2 == 1) {
            ans[level-1].push_back(root->val);
        }        
        else {
            // right
            ans[level-1].insert(ans[level-1].begin(), root->val);
        }

        traverse(root->left, level+1, ans);
        traverse(root->right, level+1, ans);
    }
};


class Solution {
public:
    vector<vector<int> > Print(TreeNode* pRoot) {
        vector<vector<int>> ans;
        if(pRoot == nullptr) {
            return ans;
        }

        queue<TreeNode*> q;
        q.push(pRoot);
        int level = 1;
        
        while(!q.empty()) {            
            ans.push_back(vector<int>());
            int size = q.size();
            for(int i = 0; i < size; i++) {
                TreeNode* cur = q.front();
                q.pop();
                ans[level-1].push_back(cur->val);
                if(cur->left) {
                    q.push(cur->left);
                }
                if(cur->right) {
                    q.push(cur->right);
                }
            }
            ++level;
        }

        for(int i = 0; i < ans.size(); i++) {
            if(i % 2 == 1) {
                reverse(ans[i].begin(), ans[i].end());
            }
        }
        return ans;
    }
};