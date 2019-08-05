class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int> v;
        int cur = 1;
        for(int i = 0; i < n; i++) {
            v.push_back(cur);
            if(cur * 10 <= n) {
                cur *= 10;
            } 
            else if(cur % 10 != 9 && cur + 1 <= n) {
                cur++;
            }
            else {
                while((cur / 10) % 10 == 9) {
                    cur /= 10;
                }
                cur = cur / 10 + 1;
            }
        }
        return v;
    }
};


struct node
{
    node** bucket = NULL;
};

class Solution {
public:
    vector<int> lexicalOrder(int n) {
        node* root = new node();
        for(int i=1; i<=n; i++){
            int rank = 1;
            while(i / (rank*10) != 0) rank *= 10;
            node* s = root;
            while(rank != 0){
                int remain = (i/rank) % 10;
                if(s->bucket == NULL){
                    s->bucket = new node*[10];
                    for(int i=0; i<10; ++i) s->bucket[i] = NULL;
                }
                if(s->bucket[remain] == NULL){
                    s->bucket[remain] = new node();
                }
                s = s->bucket[remain];
                rank /= 10;
            }
        }
        vector<int> ans;
        if(root->bucket != NULL){
            for(int i = 0; i<10 ;++i){
                if(root->bucket[i] != NULL){
                    ans.push_back(i);
                    traverF(root->bucket[i], ans, i*10);
                }
            }   
        }
        delete root;
        return ans;
    }

    void traverF(node* root,vector<int>& ans,int prefix){
        if(root->bucket != NULL){
           for(int i = 0; i<10; ++i){
                if(root->bucket[i] != NULL){
                    ans.push_back(i+prefix);
                    traverF(root->bucket[i], ans, (i+prefix)*10);
                }
            } 
        }
        delete root;
    }    
};


class Solution {
public:
    
    struct Node {
        Node* child[10];
        Node() {
            for(int i = 0; i <= 9; i++) child[i] = nullptr;
        }
    };

    vector<int> lexicalOrder(int n) {
        Node* root = new Node();
        int cur, rank; 

        // 构建十叉树
        for(int i = 1; i <= n; i++) {
            rank = 1;

            // 获取数字的位数
            while(i / (rank * 10))  rank *= 10;
            
            // 从数字的最高位开始构建数
            Node* s = root;
            while(rank) {
                cur = (i / rank) % 10;
                if(s->child[cur] == nullptr) {
                    s->child[cur] = new Node();
                }
                s = s->child[cur];
                rank /= 10;
            }
        }

        vector<int> ans;
        // 检索，获取结果
        for(int i = 1; i <= 9; i++) {
            if(root->child[i] == nullptr)   continue;
            ans.push_back(i);
            helper(ans, i*10, root->child[i]);
        }
        return ans;
    }

    // 检索节点
    void helper(vector<int>& ans, int prefix, Node* node) {
        if(node == nullptr) return;
        for(int i = 0; i <= 9; i++) {
            if(node->child[i]) {
                ans.push_back(prefix + i);
                helper(ans, (prefix + i) * 10, node->child[i]);
            }
        }
    }
};
