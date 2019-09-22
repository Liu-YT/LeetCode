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
    int TreeDepth(TreeNode* pRoot) {
        if(pRoot == nullptr) {
            return 0;
        }

        int lDepth = TreeDepth(pRoot->left);
        int rDepth = TreeDepth(pRoot->right);

        return max(lDepth, rDepth) + 1;
    }
};