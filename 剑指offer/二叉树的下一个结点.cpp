/*
struct TreeLinkNode {
    int val;
    struct TreeLinkNode *left;
    struct TreeLinkNode *right;
    struct TreeLinkNode *next;
    TreeLinkNode(int x) :val(x), left(NULL), right(NULL), next(NULL) {
        
    }
};
*/
class Solution {
public:
    TreeLinkNode* GetNext(TreeLinkNode* pNode) {
        TreeLinkNode* root = pNode;
        while(root->next) {
            root = root->next;
        }

        vector<TreeLinkNode*> nodes;
        inOrder(root, nodes);

        for(int i = 0; i < nodes.size(); i++) {
            if(nodes[i] == pNode) {
                if(i == nodes.size()-1) {
                    return nullptr;
                }
                else {
                    return nodes[i+1];
                }
            }
        }
        return nullptr;
    }

    void inOrder(TreeLinkNode* node, vector<TreeLinkNode*> &nodes) {
        if(!node) {
            return;
        }

        if(node->left) {
            inOrder(node->left, nodes);
        }

        nodes.push_back(node);

        if(node->right) {
            inOrder(node->right, nodes);
        }
    }
};

/*
链接：https://www.nowcoder.com/questionTerminal/9023a0c988684a53960365b889ceaf5e?answerType=1&f=discussion
来源：牛客网

可以把中序下一结点归为几种类型：

1. 有右子树，下一结点是右子树中的最左结点，例如 B，下一结点是 H

2. 无右子树，且结点是该结点父结点的左子树，则下一结点是该结点的父结点，例如 H，下一结点是 E

3. 无右子树，且结点是该结点父结点的右子树，则我们一直沿着父结点追朔，直到找到某个结点是其父结点的左子树，
如果存在这样的结点，那么这个结点的父结点就是我们要找的下一结点。例如 I，下一结点是 A；
例如 G，并没有符合情况的结点，所以 G 没有下一结点

 */

class Solution {
public:
    TreeLinkNode* GetNext(TreeLinkNode* pNode) {
        if(!pNode) {
            return nullptr;
        } 

        // 情况 1
        if(pNode->right) {
            TreeLinkNode* node = pNode->right;
            while(node->left) {
                node = node->left;
            }
            return node;
        }
        
        // 情况 2
        if(pNode->next && pNode == pNode->next->left) {
            return pNode->next;
        }

        // 情况 3
        if(pNode->next) {
            TreeLinkNode* node = pNode;
            while(node->next && node != node->next->left) {
                node = node->next;
            }
            return node->next;
        }

        return nullptr;
    }
};