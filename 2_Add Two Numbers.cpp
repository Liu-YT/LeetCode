/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int preIn = 0;
        int num = 0;
        ListNode* a = l1;
        ListNode* b = l2;
        ListNode* root = NULL;
        ListNode* node = NULL;
        ListNode* preNode = NULL;
        while(a != NULL && b != NULL) {
        	num = (preIn + a->val + b->val) % 10;
        	if(!root) {
        		node = new ListNode(num);
        		root = preNode = node;
        	}
        	else {
        		node = new ListNode(num);
        		preNode->next = node;
        		preNode = node;
        	}
        	preIn = (a->val + b->val + preIn) / 10;
        	a = a->next;
        	b = b->next;
        }
        while(a != NULL) {
        	num = (preIn + a->val) % 10;
    		node = new ListNode(num);
    		preNode->next = node;
    		preNode = node;
        	preIn = (a->val + preIn) / 10;
        	a = a->next;
        }
        while(b != NULL) {
        	num = (preIn + b->val) % 10;
    		node = new ListNode(num);
    		preNode->next = node;
    		preNode = node;
        	preIn = (b->val + preIn) / 10;
        	b = b->next;
        }

        if(preIn) {
        	node = new ListNode(preIn);
    		preNode->next = node;
        }

        return root;
    }
};