/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// 中序，输出第k个
class Solution {
public:

    void inorder(TreeNode* node, vector<int> &nums) {
        if(node == nullptr) return;
        inorder(node->left, nums);
        nums.push_back(node->val);
        inorder(node->right, nums);
    }

    int kthSmallest(TreeNode* root, int k) {
        vector<int> nums;
        inorder(root, nums);
        return nums[k-1];
    }
};

class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        stack<TreeNode*> s;
        // vector<int> nums;
        TreeNode* node = root;
        while(!s.empty() || node != nullptr) {
            while(node) {
                s.push(node);
                node = node->left;
            }

            node = s.top();
            k--;
            if(k == 0)  return node->val;
            s.pop();
            // nums.push_back(node->val);
            node = node->right;
        }
        // for(int i = 0; i < nums.size(); i++)    cout << nums[i] << " ";
        return -1;
    }
};