/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() {}

    Node(int _val, Node* _left, Node* _right, Node* _next) {
        val = _val;
        left = _left;
        right = _right;
        next = _next;
    }
};
*/
class Solution {
public:
    Node* connect(Node* root) {
        if(root == NULL)    return root;
        queue<pair<Node*, int>> q;
        q.push(make_pair(root, 0));
        root->next = NULL;
        while (!q.empty()) {
            auto cur = q.front();
            q.pop();
            if(cur.first->left != NULL) {
                q.push(make_pair(cur.first->left, cur.second + 1));
            }
            if(cur.first->right != NULL) {
                q.push(make_pair(cur.first->right, cur.second + 1));
            }
            if(!q.empty() && q.front().second == cur.second) {
                cur.first->next = q.front().first;
            }
        }
        return root;        
    }
};