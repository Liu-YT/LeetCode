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
    bool isSymmetrical(TreeNode* pRoot) {
        if(pRoot == nullptr) {
            return true;
        }

        return isEqual(pRoot->left, pRoot->right);
    }

    bool isEqual(TreeNode* a, TreeNode* b) {
        if(a == nullptr && b == nullptr) {
            return true;
        }

        if((a && !b) || (!a && b) || (a->val != b->val)) {
            return false;
        }

        return isEqual(a->left, b->right) && isEqual(a->right, b->left); 
    }
};