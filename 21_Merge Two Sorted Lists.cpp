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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    	ListNode* root = NULL;
		ListNode* pre = NULL;
		ListNode* cur = NULL;
		while(l1 != NULL && l2 != NULL) {
			if(l1->val >= l2->val) {
				pre = cur;
				cur = new ListNode(l2->val);
				if(pre == NULL)	root = pre = cur;
				else	pre->next = cur;
				l2 = l2->next;
			}
			else {
				pre = cur;
				cur = new ListNode(l1->val);
				if(pre == NULL) root = pre = cur;
				else	pre->next = cur;
				l1 = l1->next;
			}
		}  
		while(l1 != NULL) {
			pre = cur;
			cur = new ListNode(l1->val);
			if(pre == NULL)	root = pre = cur;
			else	pre->next = cur;
			l1 = l1->next;
		} 
		while(l2 != NULL) {
			pre = cur;
			cur = new ListNode(l2->val);
			if(pre == NULL)	root = pre = cur;
			else	pre->next = cur;
			l2 = l2->next;
		} 

		return root;
    }
};