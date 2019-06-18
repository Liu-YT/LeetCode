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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
    	if(lists.size() == 0)	return NULL;

    	ListNode* h = lists[0];
    	for(int i = 1; i < lists.size(); ++i) {
    		h = merge(h, lists[i]);
    	}
    	return h;
    }

    ListNode* merge(ListNode* a, ListNode* b) {
    	ListNode* head = NULL, *n = NULL;
    	while(a != NULL && b != NULL) {
			if(a->val > b->val) {
				if(head == NULL) {
	    			n = head = b;
				} else {
					n->next = b;
					n = n->next;
				}
	    		b = b->next;
	    	}
	    	else {
				if(head == NULL) {
	    			n = head = a;
				}  else {
					n->next = a;
					n = n->next;
				}
	    		a = a->next;
	    	}
    	}
    	if(a != NULL || b != NULL) {
    		ListNode* temp = (a == NULL) ? b : a;
    		if(head == NULL)
    			head = temp;
    		else
    			n->next = temp;

    	}

    	return head;
    }
};