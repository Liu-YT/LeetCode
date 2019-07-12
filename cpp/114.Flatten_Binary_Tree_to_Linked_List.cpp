/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

 /* 
    这题的思路比较简单吧，对于一个节点，先判断起是否包含左结点
    如果左结点存在，则将其右子树flatten后，加到节点左子树flatten后的最后一个节点的右节点上
    如果左结点不存在，则直接将其右子树flatten化即可
 */
class Solution {
public:
    void flatten(TreeNode* root) {
        if(root == NULL) {
            return;
        }
        flatten(root->right);
        TreeNode* right = root->right;
        if(root->left != NULL) {
            flatten(root->left);
            TreeNode* left = root->left;
            root->left = NULL;
            root->right = left;
            while(left->right != NULL) {
                left = left->right;
            }
            left->right = right;
        }
    }
};