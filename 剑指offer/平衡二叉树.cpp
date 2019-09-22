class Solution {
public:
    bool IsBalanced_Solution(TreeNode* pRoot) {
        if(pRoot == nullptr) {
            return true;
        }

        if(pRoot->left == nullptr && pRoot->right == nullptr) {
            return true;
        }

        int lDepth = TreeDepth(pRoot->left);
        int rDepth = TreeDepth(pRoot->right);

        if(abs(lDepth - rDepth) <= 1) {
            return IsBalanced_Solution(pRoot->left) && IsBalanced_Solution(pRoot->right);
        }
        else {
            return false;
        }
    }

    int TreeDepth(TreeNode* pRoot) {
        if(pRoot == nullptr) {
            return 0;
        }

        int lDepth = TreeDepth(pRoot->left);
        int rDepth = TreeDepth(pRoot->right);

        return max(lDepth, rDepth) + 1;
    }
};