/*
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};*/
class Solution {
public:
    vector<int> PrintFromTopToBottom(TreeNode* root) {
        vector<int> ans;

        if(root == nullptr) {
            return ans;
        }

        queue<TreeNode*> q;
        q.push(root);
    
        while(!q.empty()) {
            TreeNode* node = q.front();
            q.pop();
            ans.push_back(node->val);

            if(node->left) {
                q.push(node->left);
            }

            if(node->right) {
                q.push(node->right);
            }
        }

        return ans;
    }
};