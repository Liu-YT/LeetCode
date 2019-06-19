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
    ListNode* rotateRight(ListNode* head, int k) {
    	if(head == NULL || k == 0)	return head;
    	ListNode *a = head, *preA = head, *tail = NULL;
    	int size = 0;
    	while(a) {
    		tail = a;
    		a = a->next;
    		++size;
    	}
    	
    	k = k % size;
    	if(k == 0)	return head;
    	k = size - k;
    	a = head;
    	while(k--) {
    		preA = a;
    		a = a->next;
    	}
    	preA->next = NULL;
    	tail->next = head;
    	head = a;
    	return head;
    }
};

