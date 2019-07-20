/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node() {}

    Node(int _val, Node* _next, Node* _random) {
        val = _val;
        next = _next;
        random = _random;
    }
};
*/
class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*, Node*> m;
        return help(head, m);
    }

    Node *help(Node *node, unordered_map<Node *, Node *>& m) {
        if(node == nullptr) return nullptr;
        if(m.count(node)) return m[node];
        m[node] = new Node(node->val);
        m[node]->next = help(node->next, m);
        m[node]->random = help(node->random, m);
        return m[node];
    } 
};