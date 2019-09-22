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
        return ans;
    }
};