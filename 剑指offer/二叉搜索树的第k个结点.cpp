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
    TreeNode* KthNode(TreeNode* pRoot, int k) {
        
        TreeNode* node = pRoot;
        
        stack<TreeNode*> s;

        while(node || !s.empty()) {
            while(node) {
                s.push(node);
                node = node->left;
            }

            if(node == nullptr) {
                node = s.top();
                s.pop();
            }

            if(k == 1) {
                return node;
            }
            else {
                k--;
                node = node->right;
            }
        }

        return nullptr;
    } 
};