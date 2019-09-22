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
    TreeNode* Convert(TreeNode* pRootOfTree) {
        if(pRootOfTree == nullptr || (pRootOfTree->left == nullptr && pRootOfTree->right == nullptr)) {
            return pRootOfTree;
        }

        TreeNode* right = Convert(pRootOfTree->right);

        if(right) {
            right->left = pRootOfTree;
            pRootOfTree->right = right;
        }

        TreeNode* left = Convert(pRootOfTree->left);
        TreeNode* head = left;
        while(left && left->right) {
            left = left->right;
        }

        if(left) {
            left->right = pRootOfTree;
            pRootOfTree->left = left;
        }

        return head == nullptr ? pRootOfTree : head;
    }
};