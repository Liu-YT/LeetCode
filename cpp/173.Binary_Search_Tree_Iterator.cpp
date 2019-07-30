/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
public:
    BSTIterator(TreeNode* root) {
        this->root = root;
        inorder(root);
        this->cur = -1;
    }
    
    void inorder(TreeNode* node) {
        if(!node)   return;
        inorder(node->left);
        nums.push_back(node->val);
        inorder(node->right);
    }

    /** @return the next smallest number */
    int next() {
        if(cur+1 < nums.size())   return nums[++cur];
        return -1;
    }
    
    /** @return whether we have a next smallest number */
    bool hasNext() {
        if(cur+1 < nums.size()) return true;
        return false;
    }
private:
    int cur;
    TreeNode* root;
    vector<int> nums;
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */