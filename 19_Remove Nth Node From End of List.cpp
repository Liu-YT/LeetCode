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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
    	ListNode* a = head, *b = head, *preB = NULL;
    	int i = 1;
    	while(i++ <= n)	a = a->next;
    	while(a != NULL) {
    		preB = b;
    		b = b->next;
    		a = a->next;
    	}
    	if(preB == NULL)	return head->next;
    	else {
    		preB->next = b->next;
    		return head;
    	}
    }
};