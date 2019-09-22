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
    char* Serialize(TreeNode *root) {    
        if(!root) {
            return "#";
        }

        string s = to_string(root->val);
        s.push_back(',');

        char* left = Serialize(root->left);
        char* right = Serialize(root->right);

        char *ret = new char[strlen(left) + strlen(right) + s.size()];

        strcpy(ret, s.c_str());
        strcat(ret, left);
        strcat(ret, right);
        return ret;
    }


    TreeNode* Deserialize(char *str) {
        return decode(str);
    }

    TreeNode* decode(char *&str) {
        if(*str == '#') {
            str++;
            return nullptr;
        }

        int num = 0;
        while(*str != ',') {
            num = num * 10 + (*(str++) - '0');
        }
        str++;
        TreeNode* root = new TreeNode(num);
        root->left = decode(str);
        root->right = decode(str);
        return root;
    }
};