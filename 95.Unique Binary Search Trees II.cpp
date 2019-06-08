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
    vector<TreeNode*> generateTrees(int n) {
    	if(!n) 
    		return vector<TreeNode*>();
    	
    	vector<TreeNode*> v = myGenerate(1, n);
        return v;
    }

    vector<TreeNode*> myGenerate(int start, int end) {
    	vector<TreeNode*> v;
    	if(start > end)	return v;

    	for(int i = start; i <= end; ++i) {
    		
    		vector<TreeNode*> left = myGenerate(start, i-1);
    		vector<TreeNode*> right = myGenerate(i + 1, end);

			if(!left.size())	left.push_back(NULL);
			if(!right.size())	right.push_back(NULL);

			for(int j = 0; j < left.size(); ++j) {				
				for(int k = 0; k < right.size(); ++k) {
					TreeNode* node = new TreeNode(i);
					node->left = left[j];
					node->right = right[k];
					v.push_back(node);
				}
			}
    	}
        return v;	
    }
};