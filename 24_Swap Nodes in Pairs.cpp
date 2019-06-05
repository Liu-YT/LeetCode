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
    ListNode* swapPairs(ListNode* head) {
    	ListNode* h = head;
		int count = 0;
		while(h != NULL) {
			if(count % 2 == 0 && h->next != NULL) {
				int val = h->val;
				h->val = h->next->val;
				h->next->val = val;
			}
			++count;
			h = h->next;
		}
		return head;
    }
};