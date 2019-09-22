/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* reConstructBinaryTree(vector<int> pre,vector<int> vin) {
        if(pre.size() == 0)
            return nullptr;

        TreeNode *node = new TreeNode(pre[0]);

        if(pre.size() == 1) {
            return node;
        }

        int i;
        for(i = 0; i < vin.size(); i++) {
            if(pre[0] == vin[i]) {
                break;
            }
        }

        vector<int> lvin(vin.begin(), vin.begin() + i);
        vector<int> lpre(pre.begin() + 1, pre.begin() + i + 1);
        node->left = reConstructBinaryTree(lpre, lvin);

        vector<int> rvin(vin.begin() + i + 1, vin.end());
        vector<int> rpre(pre.begin() + i + 1, pre.end());
        node->right = reConstructBinaryTree(rpre, rvin);

        return node;
    }
};