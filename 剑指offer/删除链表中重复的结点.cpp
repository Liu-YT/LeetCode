/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
        val(x), next(NULL) {
    }
};
*/
class Solution {
public:
    ListNode* deleteDuplication(ListNode* pHead) {
        ListNode *pre = new ListNode(0);
        pre->next = pHead;
        
        ListNode *node = pHead, *pNode = pre;

        while(node) {
            int cur = node->val;
            ListNode *cNode = node->next;
            
            while(cNode && cNode->val == cur) {
                ListNode* tmp = cNode->next;
                delete cNode;
                cNode = tmp;
            }

            if(node->next != cNode) {
                delete node;
                node = cNode;
                pNode->next = node;
            }
            else {
                pNode = node;
                node = node->next;
            }
        }


        ListNode* nHead = pre->next;
        delete pre;
        return nHead;
    }
};