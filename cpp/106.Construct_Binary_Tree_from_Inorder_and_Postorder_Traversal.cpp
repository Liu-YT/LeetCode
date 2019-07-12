/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if (!postorder.size())
            return nullptr;
        return build(postorder, 0, postorder.size() - 1, inorder, 0, inorder.size() - 1);
    }

    TreeNode* build(vector<int> &postorder, int s1, int e1, vector<int> &inorder, int s2, int e2) {
        if(s1 > e1)    return NULL;
        TreeNode* node = new TreeNode(postorder[e1]);
        int index = -1;
        for(int i = s2; i <= e2; ++i) {
            if(inorder[i] == node->val) {
                index = i;
                break;
            }
        }

        if(index > s2) {
            node->left = build(postorder, s1, s1 + index - s2, inorder, s2, index - 1);
        }

        if(index < e2) {
            node->right = build(postorder, s1 + index - s2 + 1, e1 - 1, inorder, index + 1, e2);
        }
        return node;
    }
};