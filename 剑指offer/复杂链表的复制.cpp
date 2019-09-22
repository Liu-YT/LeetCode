/*
struct RandomListNode {
    int label;
    struct RandomListNode *next, *random;
    RandomListNode(int x) :
            label(x), next(NULL), random(NULL) {
    }
};
*/

// 超内存
class Solution {
public:
    RandomListNode* Clone(RandomListNode* pHead) {
        if(pHead == nullptr) {
            return nullptr;
        }
        
        unordered_map<RandomListNode*, RandomListNode*> m;
        
        RandomListNode *head = nullptr;
        
        RandomListNode *node = pHead;
        
        while(node) {
            copy(node, m);
            node = node->next;
        }
        return m[pHead];
    }

    RandomListNode* copy(RandomListNode* node, unordered_map<RandomListNode*, RandomListNode*> &m) {
        if(m.count(node)) { 
            return m[node];
        }

        if(node == nullptr) {
            return nullptr;
        }

        RandomListNode* nNode = new RandomListNode(node->label);
        nNode->next = copy(node->next, m);
        nNode->random = copy(node->random, m);
        m[node] = nNode;
        return nNode;
    }
};

class Solution {
public:
    RandomListNode* Clone(RandomListNode* pHead) {
        if(pHead == nullptr) {
            return nullptr;
        }
        
        RandomListNode *cur = pHead;
        //1、复制每个结点，如复制结点A得到A1，将结点A1插到结点A后面
        while(cur) {
            RandomListNode* nNode = new RandomListNode(cur->label);
            nNode->next = cur->next;
            cur->next = nNode;
            cur = nNode->next;
        }
        cur = pHead;

        // 2. 重新遍历链表，复制老结点的随机指针给新结点，如A1.random = A.random.next;
        while(cur) {
            cur->next->random = (cur->random == nullptr) ? nullptr : cur->random->next;
            cur = cur->next->next;
        }
        cur = pHead;

        // 3、拆分链表，将链表拆分为原链表和复制后的链表
        RandomListNode* nHead = cur->next;
        while(cur) {
            RandomListNode* node = cur->next;
            cur->next = node->next;
            node->next = (cur->next == nullptr) ? nullptr : node->next->next;
            cur = cur->next;
        }

        return nHead;
    }
};
