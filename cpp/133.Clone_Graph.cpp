/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;

    Node() {}

    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

/* solution 1 */
class Solution {
public:
    Node* cloneGraph(Node* node) {
        unordered_map<Node*, Node*> m;
        return sol(node, m);
    }

    Node* sol(Node* node, unordered_map<Node*, Node*> &m) {
        if(node == nullptr) return nullptr;
        if(!m.count(node)) {
            m[node] = new Node(node->val, vector<Node*>{});
            for(auto n : node->neighbors) {
                m[node]->neighbors.push_back(sol(n, m));
            }
        }
        return m[node];
    }
};


/* solution 2 */
class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(node == nullptr) return nullptr;
        unordered_map<Node*, Node*> m;
        queue<Node*> q;
        q.push(node);
        m[node] = new Node(node->val, vector<Node *>{});
        while(!q.empty()) {
            Node* front = q.front();
            q.pop();
            for(auto n : front->neighbors) {
                if(!m.count(n)) {
                    m[n] = new Node(n->val, vector<Node *>{});
                    q.push(n);
                }
                m[front]->neighbors.push_back(m[n]);
            }
        }
        return m[node];
    }
};