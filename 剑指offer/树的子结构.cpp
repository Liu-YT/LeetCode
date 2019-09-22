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
    bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2) {
        if(pRoot2 == nullptr || pRoot1 == nullptr) {
            return false;
        }

        return like(pRoot1, pRoot2) || HasSubtree(pRoot1->left, pRoot2) || HasSubtree(pRoot1->right, pRoot2);
    }

    bool like(TreeNode* a, TreeNode* b) {
        if(b == nullptr) {
            return true;
        }

        if(a == nullptr) {
            return false;
        }

        if(a->val == b->val) {
            return like(a->left, b->left) && like(a->right, b->right);
        }

        return false;
    }
};