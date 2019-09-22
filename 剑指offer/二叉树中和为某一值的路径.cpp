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
    vector<vector<int> > FindPath(TreeNode* root,int expectNumber) {
        vector<vector<int>> p;
        if(root == nullptr) {
            return p;
        }

        vector<int> cur;
        path(root, expectNumber, cur, p);
        
        return p;
    }

    void path(TreeNode* node, int expectNumber, vector<int> cur, vector<vector<int>> &p) {
        if(node == nullptr) {
            return;
        }

        if(node->left == nullptr && node->right == nullptr) {
            if(expectNumber == node->val) {
                cur.push_back(node->val);
                p.push_back(cur);
            } 
            return;
        }

        cur.push_back(node->val);
        path(node->left, expectNumber - node->val, cur, p);
        path(node->right, expectNumber - node->val, cur, p);
    }
};